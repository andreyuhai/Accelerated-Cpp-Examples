#include "Vector.h"
#include <iostream>

template <class T> Vec<T>& Vec<T>::operator=(const Vec& rhs) {
	// Check for self-assignment
	if(&rhs != this) {

		// free the array in the left-hand side
		uncreate();

		// copy elements from the right-hand to the left-hand side
		create(rhs.begin(), rhs.end());
	}

	return *this;
}

template <class T> void Vec<T>::clear() {
	if(data)
		uncreate();	
}

template <class T> typename Vec<T>::iterator Vec<T>::erase(iterator position) {
		
	size_type new_size = size() - 1;
	iterator new_data = alloc.allocate(new_size);
	
	// To return the appropriate iterator to the last element that followed the erased one
	ptrdiff_t position_index = position - data;

	if(position == data) {
		std::uninitialized_copy(data + 1, avail, new_data);
	} else if(position < avail) {
		// With the inner uninitialized_copy function first we copy the range before the element that position points to
		// And then with the outer uninitialized_copy function we copy the range after the element that position points to
		std::uninitialized_copy(position + 1, avail, std::uninitialized_copy(data, position, new_data));
	}

	// return the old space
	uncreate(); 

	// reset pointers to point to the newly allocated space
	data = new_data;
	limit = avail = data + new_size;

	return new_data + position_index;
}

template <class T> void Vec<T>::uncreate() {
	if(data) {
		// destroy (in reverse order) the elements that were constuctred
		iterator it = avail;
		while(it != data) {
			alloc.destroy(--it);
		}

		// return all the space that was allocated
		alloc.deallocate(data, limit - data);
	}
	// reset pointers to indicate that the Vec is empty again
	data = limit = avail = 0;
}

template <class T> void Vec<T>::push_back(const T& val) {
	if(avail == limit) { // get space if needed
		grow();
	}

	unchecked_append(val); // append the new element
}

template <class T> void Vec<T>::create() {
	data = avail = limit = 0;
}

template <class T> void Vec<T>::create(size_type n, const T& val) {
	data = alloc.allocate(n);
	limit = avail = data + n;
	std::uninitialized_fill(data, limit, val);
}

template <class T> void Vec<T>::create(const_iterator i, const_iterator j) {
	data = alloc.allocate(j -i);
	limit = avail = std::uninitialized_copy(i, j, data);
}

template <class T> void Vec<T>::grow() {
	// when growing allocate twice as much space as currently in use
	size_type new_size = std::max(2 * (limit - data), ptrdiff_t(1));

	// allocate new space and copy existing elements to the new space
	iterator new_data = alloc.allocate(new_size);
	iterator new_avail = std::uninitialized_copy(data, avail, new_data);

	// return the old space
	uncreate();

	// reset pointers to point to the newly allocated space
	data = new_data;
	avail = new_avail;
	limit = data + new_size;
}

// assumes avail points at allocated, but uninitialized space
template <class T> void Vec<T>::unchecked_append(const T& val) {
	alloc.construct(avail++, val);
}

// For template functions either you move all your function definitions into the header or 
// explicitly instantiate the template like below.
template class Vec<int>;
template class Vec<std::string>;
template class Vec<char>;
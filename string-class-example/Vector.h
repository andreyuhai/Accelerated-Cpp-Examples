#include <memory>

template <class T> class Vec {
	public:
		typedef T* iterator;
		typedef const T* const_iterator;
		typedef size_t size_type;
		typedef T value_type;

		Vec() { create(); }
		~Vec() { uncreate(); }
		Vec(const Vec& v) { create(v.begin(), v.end()); }
		explicit Vec(size_type n, const T& val = T()) { create(n, val); }

		T& operator[](size_type i) { return data[i]; }
		const T& operator[](size_type i) const { return data[i]; }
		Vec& operator=(const Vec&);
		size_type size() const { return avail - data; }

		iterator begin() {return data; }
		const_iterator begin() const { return data; }

		iterator end() { return avail; }
		const_iterator end() const { return avail; }

		void push_back(const T&);
		void clear();
		iterator erase(iterator position);
	private:
		iterator data; // pointer to the first element in the Vec
		iterator avail; // pointer to (one past) the last constructed element
		iterator limit; // now points to (one past) the last available element

		std::allocator<T> alloc; // Object to handle memory allocation

		// allocate and initialize the underlying array
		void create();
		void create(size_type, const T&);
		void create(const_iterator, const_iterator);

		// destroy the elements in the array and free the memory
		void uncreate();

		// support functions for push_back
		void grow();
		void unchecked_append(const T&);
};
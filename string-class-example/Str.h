#include "Vector.h"
#include <algorithm>
#include <istream>
#include <ostream>
#include <iterator>
#include <cstring>

class Str {
	friend std::istream& operator>>(std::istream&, Str&);
public:
	typedef Vec<char>::size_type size_type;

	// default constructor
	Str() {}

	// create an Str containing n copies of c
	Str(size_type n, char c) : data(n, c) {}

	// create an Str from a null-terminated array of char
	Str(const char* cp) {
		std::copy(cp, cp + strlen(cp), std::back_inserter(data));
	}

	// create an Str from the range denoted by iterators b and e
	template <class In> Str(In b, In e) {
		std::copy(b, e, std::back_inserter(data));
	}

	char& operator[](size_type i) { return data[i]; }
	const char& operator[](size_type i) const { return data[i]; }
	size_type size() const { return data.size(); }
	Str& operator+=(const Str&);

private:
	Vec<char> data;

};


std::ostream& operator<<(std::ostream&, const Str&);
Str operator+(const Str&, const Str&);
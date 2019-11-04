#ifndef STUDENT_INFO_H
#define STUDENT_INFO_H

#include <istream>
#include "core.h"
#include "grad.h"

class Student_info {
public:
	// constructors and copy control
	Student_info(): cp(0) {}
	Student_info(std::istream& is): cp(0) { read(is); }
	Student_info(const Student_info& s) : cp(0) { if(s.cp) cp = s.cp->clone(); } // copy constructor
	Student_info& operator=(const Student_info&);
	~Student_info() { delete cp; }

	// operations
	std::istream& read(std::istream&);

	std::string name() const { 
		if(cp) return cp->name();
		else throw std::runtime_error("Uninitialized Student");
	}

	double grade() const {
		if(cp) return cp->grade();
		else throw std::runtime_error("Uninitialized Student");
	}

	static bool compare(const Student_info& s1, const Student_info& s2) {
		return s1.name() < s2.name();
	}
private:
	Core *cp;
};

#endif
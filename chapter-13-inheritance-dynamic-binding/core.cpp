#include "core.h"
#include <string>
#include "helpers.h"

std::string Core::name() const { return n; }

double Core::grade() const {
	return ::grade(midterm, final, homework);
}

std::istream& Core::read_common(std::istream& in) {
	// read and store the student's name and exam grades
	in >> n >> midterm >> final;
}

std::istream& Core::read(std::istream& in) {
	read_common(in);
	read_hw(in, homework);
	return in;
}

bool compare(const Core& c1, const Core& c2) {
	return c1.name() < c2.name();
}

bool compare_grades(const Core& c1, const Core& c2) {
	return c1.grade() < c2.grade();
}

bool compare_core_ptrs(const Core* cp1, const Core* cp2) {
	return compare(*cp1, *cp2);
}

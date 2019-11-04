#include "student_info.h"
#include "helpers.h"
#include <iostream>
#include <algorithm>
#include <iomanip>

int main() {

	std::vector<Student_info> students;
	Student_info record;
	std::string::size_type maxlen = 0;

	// read and store the data
	while(record.read(std::cin)) {
		maxlen = std::max(maxlen, record.name().size()); // dereference
		students.push_back(record);
	}

	// pass the version of compare that works on pointers
	std::sort(students.begin(), students.end(), Student_info::compare);

	// write the names and grades
	for(std::vector<Student_info>::size_type i = 0; i != students.size(); i++) {
		// students[i] is a pointer that we dereference to call the functions
		std::cout << students[i].name()
		<< std::string(maxlen + 1 - students[i].name().size(), ' ');

		try {
			double final_grade = students[i].grade(); // Core::grade
			std::streamsize prec = std::cout.precision();
			std::cout << std::setprecision(3) << final_grade
			<< std::setprecision(prec) << std::endl;
		} catch(std::domain_error e) {
			std::cout << e.what() << std::endl;
		}
	}
	return 0;
}
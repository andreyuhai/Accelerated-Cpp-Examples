#ifndef CORE_H
#define CORE_H

#include <istream>
#include <string>
#include <vector>

class Core {
	friend class Student_info;
public:
	// default constructor for Core
	Core(): midterm(0), final(0) {}
	virtual ~Core() {}
	// build a Core from an istream
	Core(std::istream& is) { read(is); }
	std::string name() const;
	virtual std::istream& read(std::istream&);
	virtual double grade() const;
protected:
	std::istream& read_common(std::istream&);
	double midterm, final;
	std::vector<double> homework;
	virtual Core* clone() const { return new Core(*this); }
private:
	std::string n;
};

bool compare(const Core&, const Core&);
bool compare_grades(const Core&, const Core&);
bool compare_core_ptrs(const Core*, const Core*);

#endif
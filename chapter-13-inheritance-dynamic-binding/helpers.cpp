#include "helpers.h"
#include <istream>
#include <vector>
#include <algorithm>

std::istream& read_hw(std::istream& in, std::vector<double>& hw) {

	if(in) {
		hw.clear();

		double x;
		while(in >> x)
			hw.push_back(x);
		in.clear();
	}

	return in;
}

double grade(double midterm, double final, const std::vector<double>& homework) {
	
	return 0.2 * midterm + 0.4 * final + 0.4 * median(homework);
}

double median(std::vector<double> vec) {
	typedef std::vector<double>::size_type vec_sz;

	vec_sz size = vec.size();
	if (size == 0)
		throw std::domain_error("median of an empty vector");

	sort(vec.begin(), vec.end());

	vec_sz mid = size / 2;

	return size % 2 == 0 ? (vec[mid] + vec[mid - 1]) / 2 : vec[mid];
}
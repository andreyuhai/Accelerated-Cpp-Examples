#include "grad.h"
#include <algorithm>
#include <istream>
#include "helpers.h"

std::istream& Grad::read(std::istream& in) {
	read_common(in);
	in >> thesis;
	read_hw(in, homework);
	return in;
}

double Grad::grade() const {
	return std::min(Core::grade(), thesis);
}


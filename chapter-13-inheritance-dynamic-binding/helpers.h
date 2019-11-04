#ifndef HELPERS_H
#define HELPERS_H

#include <istream>
#include <vector>

std::istream& read_hw(std::istream&, std::vector<double>&);
double grade(double, double, const std::vector<double>&);
double median(std::vector<double>);

#endif
#include "Str.h"
#include <iostream>

int main() {
	Str foo = "Value of foo = \"foo\"";
	std::cout << foo << std::endl;
	std::cout << "Enter new falue for foo: ";
	std::cin >> foo;
	std::cout << "New value of foo: \"" << foo << "\"" << std::endl;
	std::cout << "=============" << std::endl;

	// operator+ and operator+= example
	Str bar = "bar";
	std::cout << "bar = \"" << bar << "\"" << std::endl;
	foo += bar;
	std::cout << "(foo =+ bar) = \"" << foo << "\"" << std::endl;
	std::cout << "=============" << std::endl;
	std::cout << "foo + foo = \"" << foo + foo << "\"" << std::endl;

	


	return 0;
}
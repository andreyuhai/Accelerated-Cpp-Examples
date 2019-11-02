#include <iostream>
#include "Vector.h" 

int main(int argc, char* argv[]) {
	Vec<std::string> foo;
	foo.push_back("zero");	
	foo.push_back("one");
	foo.push_back("two");
	foo.push_back("three");
	foo.push_back("four");
	foo.push_back("five");
	foo.push_back("six");
	foo.push_back("seven");
	foo.push_back("eight");
	foo.push_back("nine");
	foo.push_back("ten");
	
	for(Vec<std::string>::const_iterator iter = foo.begin(); iter != foo.end(); iter++) 
		std::cout << *iter << std::endl;

	std::cout << "===================================" << std::endl;

	std::cout << "Deleting the two from the Vec..." << std::endl;
	foo.erase(foo.begin() + 2);

	std::cout << "New array size: " << foo.size() << std::endl << std::endl;

	for(Vec<std::string>::const_iterator iter = foo.begin(); iter != foo.end(); iter++) 
		std::cout << *iter << std::endl;

	std::cout << "===================================" << std::endl;

	std::cout << "Deleting the zero from the Vec..." << std::endl;
	foo.erase(foo.begin());

	std::cout << "New array size:" << foo.size() << std::endl << std::endl;

	for(Vec<std::string>::const_iterator iter = foo.begin(); iter != foo.end(); iter++) 
		std::cout << *iter << std::endl;

	std::cout << "===================================" << std::endl;

	std::cout << "Deleting the ten from the Vec..." << std::endl;
	foo.erase(foo.end() - 1);

	std::cout << "New array size:" << foo.size() << std::endl << std::endl;

	for(Vec<std::string>::const_iterator iter = foo.begin(); iter != foo.end(); iter++) 
		std::cout << *iter << std::endl;		

	return 0;
}
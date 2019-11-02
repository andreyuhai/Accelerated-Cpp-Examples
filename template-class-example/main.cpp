#include <iostream>
#include "Vector.h" 

int main(int argc, char* argv[]) {
	Vec<std::string> foo;
	foo.push_back("one");
	foo.push_back("two");
	foo.push_back("three");
	
	for(Vec<std::string>::const_iterator iter = foo.begin(); iter != foo.end(); iter++) 
		std::cout << *iter << std::endl;
	return 0;
}
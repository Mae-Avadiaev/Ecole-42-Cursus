#include <iostream>
#include <iomanip>

int main(void) {
	std::string brainz = "HI THIS IS BRAIN";
	std::string* stringPTR = &brainz;
	std::string& stringREF = brainz;

	std::cout << std::setw(30) << "Address of string: " << std::setw(20) << &brainz << std::endl;
	std::cout << std::setw(30) << "String pointer: " << std::setw(20) << stringPTR << std::endl;
	std::cout << std::setw(30) << "String reference: " << std::setw(20) << &stringREF << std::endl;
	std::cout << std::endl;
	std::cout << std::setw(30) << "Value of string by pointer: " << std::setw(22) << *stringPTR << std::endl;
	std::cout << std::setw(30) << "Value of string by reference: " << std::setw(22) << stringREF << std::endl;
}
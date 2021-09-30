#include "iter.hpp"
#include <string>



int main() {

	int intArr[3] = {1, 2, 3};
	iter(intArr,
	  static_cast<int>(sizeof(intArr)/sizeof(intArr[0])),
	  &addFive<int>);
	for(int i = 0; i < static_cast<int>(sizeof(intArr)/sizeof(intArr[0])); i++)
		std::cout << intArr[i];
	std::cout << std::endl;

	char string[] = "abcdef";
	iter(string,
	  static_cast<int>(sizeof(string)/sizeof(string[0])),
	  &addFive<char>);
	std::cout << string << std::endl;

	return 0;

}
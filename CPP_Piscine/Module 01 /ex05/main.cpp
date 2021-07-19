#include "Karen.hpp"

int main(void) {
	std::string command;
	Karen karen;

	do {
		std::cin >> command;
		karen.complain(command);
	} while (command.compare("EXIT"));
std::cout << "Have a good day!" << std::endl;
	return 0;
}
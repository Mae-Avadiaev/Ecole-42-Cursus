#include "Converter.hpp"

int main(int ac, char *av[]) {

	if (ac > 2) {
		std::cout << "More than one value was provided!" << std::endl;
		return 1;
	} else if (ac < 2) {
		std::cout << "No value was provided!" << std::endl;
		return 1;
	}

	Converter converter;
	converter.displayConversions(av[1]);

	return 0;

}
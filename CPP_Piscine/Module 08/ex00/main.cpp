#include "easyfind.hpp"
#include <iostream>
#include <array>

int main() {

	std::array<int, 5> arr = {1, 2, 3, 4, 5};
	for (int i = 1; i < 10; i++) {
		const int *tmp = easyfind(arr, i);
		if (tmp != arr.end()) {
			std::cout << *tmp << std::endl;
		} else {
			std::cout << "Target not found" << std::endl;
		}
	}

	return 0;
}
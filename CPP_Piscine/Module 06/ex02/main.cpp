#include "Base_A_B_C.hpp"
#include <iostream>

#define UNUSED(expr) do { (void)(expr); } while (0)

Base *generate(void) {
	int randI = rand() % 3;
	Base *res;

	if (randI == 0) {
		res = new A();
		std::cout << "Class A has been generated!" << std::endl;
	} else if (randI == 1) {
		res = new B();
		std::cout << "Class B has been generated!" << std::endl;
	} else {
		res = new C();
		std::cout << "Class C has been generated!" << std::endl;
	}
	return res;
}

void identify(Base* p) {
	if (dynamic_cast<A*>(p))
		std::cout << "A";
	else if (dynamic_cast<B*>(p))
		std::cout << "B";
	else
		std::cout << "C";
	std::cout << std::endl;
}

void identify(Base& p) {
	try {
		UNUSED(dynamic_cast<A &>(p));
		std::cout << "A" << std::endl;
	}
	catch (std::bad_cast &e) {
		try {
			UNUSED(dynamic_cast<B&>(p));
			std::cout << "B" << std::endl;
		}
		catch (std::bad_cast &e) {
			try {
				UNUSED(dynamic_cast<C &>(p));
				std::cout << "C" << std::endl;
			}
			catch (std::bad_cast &e) {
				std::cout << "This is a Base class!" << std::endl;
			}
		}
	}
}

int main() {

	Base *first = generate();
	Base *second = generate();
	Base *third = generate();

	identify(first);
	identify(second);
	identify(third);

	identify(*first);
	identify(*second);
	identify(*third);

	delete first;
	delete second;
	delete third;

	return 0;
}
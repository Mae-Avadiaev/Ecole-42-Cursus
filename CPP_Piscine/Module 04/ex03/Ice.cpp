#include "Ice.hpp"

Ice::Ice() : AMateria("ice") {
	std::cout << "Ice constructor has been called!" << std::endl;
}

Ice::Ice(const Ice &other) : AMateria(other.type) {
	std::cout << "Ice copy constructor has been called!" << std::endl;
}

Ice::~Ice() {
	std::cout << "Ice destructor has been called!" << std::endl;
}

Ice& Ice::operator=(const Ice &other) {
	std::cout << "Ice assignation operator has been called!" << std::endl;
	(void)other;
	return *this;
}

AMateria* Ice::clone() const {
	return new Ice(*this);
}

void Ice::use(ICharacter &target) {
	std::cout	<< "* shoots an ice bolt at "
				<< target.getName() << " *" << std::endl;
}

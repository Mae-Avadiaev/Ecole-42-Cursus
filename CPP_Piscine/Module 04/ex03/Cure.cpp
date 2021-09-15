#include "Cure.hpp"

Cure::Cure() : AMateria("cure") {
	std::cout << "Cure constructor has been called!" << std::endl;
}

Cure::Cure(const Cure &other) : AMateria(other.type) {
	std::cout << "Cure copy constructor has been called!" << std::endl;
}

Cure::~Cure() {
	std::cout << "Cure destructor has been called!" << std::endl;
}

Cure& Cure::operator=(const Cure &other) {
	std::cout << "Cure assignation operator has been called!" << std::endl;
	(void)other;
	return *this;
}

AMateria* Cure::clone() const {
	return new Cure(*this);
}

void Cure::use(ICharacter &target) {
	std::cout	<< "* heals " << target.getName()
				<< "'s wounds *" << std::endl;
}
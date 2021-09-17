#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal() {
	std::cout	<< "WrongAnimal constructor has been called!"
				<< std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other) : type(other.type) {}

WrongAnimal::~WrongAnimal() {
	std::cout	<< "WrongAnimal destructor has been called!"
				<< std::endl;
}

WrongAnimal& WrongAnimal::operator=(const WrongAnimal &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

std::string WrongAnimal::getType() const {
	return type;
}

void WrongAnimal::setType(std::string value) {
	type = value;
}

void WrongAnimal::makeSound() const {
	std::cout << "Bue!" << std::endl;
}
#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor has been called!" << std::endl;
	type = "Dog";
}

Dog::Dog(const Dog &other) {
	type = other.type;
}

Dog::~Dog() {
	std::cout << "Dog destructor has been called!" << std::endl;
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Chappi" << std::endl;
}
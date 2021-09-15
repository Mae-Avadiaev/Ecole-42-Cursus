#include "Dog.hpp"

Dog::Dog() {
	std::cout << "Dog constructor has been called!" << std::endl;
	type = "Dog";
	brain = new Brain();
}

Dog::~Dog() {
	delete brain;
	std::cout << "Dog destructor has been called!" << std::endl;
}

Dog::Dog(const Dog &other) {
	std::cout << "Dog copy constructor called!" << std::endl;
	type = other.type;
	brain = new Brain(*other.brain);
}

Dog& Dog::operator=(const Dog &other) {
	if (this != &other) {
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Dog::makeSound() const {
	std::cout << "Chappi" << std::endl;
}
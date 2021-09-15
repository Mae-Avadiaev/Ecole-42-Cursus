#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor has been called!" << std::endl;
	type = "Cat";
	brain = new Brain();
}

Cat::Cat(const Cat &other) {
	type = other.type;
	brain = new Brain(*other.brain);
}

Cat::~Cat() {
	delete brain;
	std::cout << "Cat destructor has been called!" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	std::cout << "Cat assignation operator has been called!" << std::endl;
	if (this != &other) {
		type = other.type;
		delete brain;
		brain = new Brain(*other.brain);
	}
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Wiscas" << std::endl;
}

void Cat::captureFirstIdea(std::string firstIdea) {
	brain->setFirstIdea(firstIdea);
}

std::string Cat::revealFirstIdea() const {
	return brain->getFirstIdea();
};
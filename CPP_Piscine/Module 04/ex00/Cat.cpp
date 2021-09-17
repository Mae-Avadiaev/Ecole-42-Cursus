#include "Cat.hpp"

Cat::Cat() {
	std::cout << "Cat constructor has been called!" << std::endl;
	type = "Cat";
}

Cat::Cat(const Cat &other) {
	type = other.type;
}

Cat::~Cat() {
	std::cout << "Cat destructor has been called!" << std::endl;
}

Cat& Cat::operator=(const Cat &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

void Cat::makeSound() const {
	std::cout << "Wiscas" << std::endl;
}
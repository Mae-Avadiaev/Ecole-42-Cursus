#include "Animal.hpp"

Animal::Animal() {
	std::cout << "Animal constructor has been called!" << std::endl;
}

Animal::Animal(const Animal &other) : type(other.type) {}

Animal::~Animal() {
	std::cout << "Animal destructor has been called!" << std::endl;
}

Animal& Animal::operator=(const Animal &other) {
	if (this != &other)
		type = other.type;
	return *this;
}

std::string Animal::getType() const {
	return type;
}

void Animal::setType(std::string value) {
	type = value;
}

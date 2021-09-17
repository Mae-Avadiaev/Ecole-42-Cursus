#include "WrongCat.hpp"

WrongCat::WrongCat() {
	std::cout << "WrongCat constructor has been called!" << std::endl;
	type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &other) {
	type = other.type;
}

WrongCat::~WrongCat() {
	std::cout << "WrongCat destructor has been called!" << std::endl;
}

WrongCat& WrongCat::operator=(const WrongCat &other) {
	if (this != &other)
		type = other.type;
	return *this;
}
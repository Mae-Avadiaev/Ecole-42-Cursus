#include "AMateria.hpp"

AMateria::AMateria(const std::string &type) : type(type) {
	std::cout << "AMaterial constructor has been called!" << std::endl;
}

AMateria::~AMateria() {
	std::cout << "AMaterial destructor has been called!" << std::endl;
}

const std::string& AMateria::getType() const {
	return type;
}

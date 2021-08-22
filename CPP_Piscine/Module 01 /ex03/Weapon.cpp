#include "Weapon.hpp"

Weapon::Weapon(std::string type) : _type(type) {}

void Weapon::setType(std::string type) {
	this->_type = type;
}

const std::string& Weapon::getType() const {
	const std::string& typeRef = this->_type;

	return typeRef;
}



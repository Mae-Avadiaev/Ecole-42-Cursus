#include "Character.hpp"

Character::Character(std::string name) : _name(name) {
	std::cout << "Character constructor has been called!" << std::endl;
	for (int i = 0; i < 4; i++)
		_inventory[i] = 0;
}

Character::Character(const Character &other) : _name(other._name) {
	std::cout << "Character copy constructor has been called!" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (other._inventory[i])
			_inventory[i] = other._inventory[i]->clone();
	}
}

Character::~Character() {
	std::cout << "Character destructor has been called!" << std::endl;
	for (int i = 0; i < 4; i++) {
		if (_inventory[i])
			delete _inventory[i];
	}
}

Character& Character::operator=(const Character &other) {
	std::cout << "Character assignation operator has been called!" << std::endl;
	if (this != &other) {
		_name = other._name;
		for (int i = 0; i < 4; i++) {
			if (_inventory[i]) {
				delete _inventory[i];
				_inventory[i] = 0;
			}
		}
		for (int j = 0; j < 4; j++) {
			if (other._inventory[j])
				_inventory[j] = other._inventory[j]->clone();
		}
	}
	return *this;
}

const std::string& Character::getName() const {
	return _name;
}

void Character::equip(AMateria* m) {
	for (int i = 0; i < 4; i++) {
		if (!_inventory[i]) {
			_inventory[i] = m;
			return;
		}
	}
}

void Character::unequip(int idx) {
	if (_inventory[idx])
		_inventory[idx] = 0;
}

void Character::use(int idx, ICharacter& target) {
	if (_inventory[idx])
		_inventory[idx]->use(target);
}
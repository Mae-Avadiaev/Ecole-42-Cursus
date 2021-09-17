#ifndef HUMANB_H
#define HUMANB_H

#include "Weapon.hpp"

class HumanB {

public:

	void attack(void) const;
	void setWeapon(Weapon& weapon);

	HumanB(std::string name);

private:

	std::string	_name;
	Weapon*		_weapon;
};

#endif
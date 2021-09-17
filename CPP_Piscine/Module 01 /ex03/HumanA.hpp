#ifndef HUMANA_H
#define HUMANA_H

#include "Weapon.hpp"

class HumanA {

public:

	void attack(void) const;

	HumanA(std::string name, Weapon& weapon);

private:

	std::string	_name;
	Weapon&		_weapon;

};

#endif
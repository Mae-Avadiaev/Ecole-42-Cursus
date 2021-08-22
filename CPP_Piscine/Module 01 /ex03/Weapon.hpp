#ifndef WEAPON_H
#define WEAPON_H

#include <string>
#include <iostream>

class Weapon {

public:

	void setType(std::string type);
	const std::string& getType(void) const;

	Weapon(std::string type);

private:

	std::string _type;

};

#endif
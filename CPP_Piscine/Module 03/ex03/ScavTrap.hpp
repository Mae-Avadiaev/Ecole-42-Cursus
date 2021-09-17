#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class ScavTrap: virtual public ClapTrap {

public:

    ScavTrap(std::string name);
    ~ScavTrap();

    void attack(const std::string target);
    void guardGate();

protected:

	unsigned int default_hp;
	unsigned int default_ep;
	unsigned int default_ad;

};

#endif

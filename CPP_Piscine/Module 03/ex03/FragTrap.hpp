#ifndef FRAGTRAP_HPP
#define FRAGTRAP_HPP

#include <iostream>
#include <string>
#include "ClapTrap.hpp"

class FragTrap: virtual public ClapTrap {

public:

    FragTrap(std::string name);
    ~FragTrap();

    void attack(const std::string target);
    void highFivesGuys(void);

protected:

	unsigned int default_hp;
	unsigned int default_ep;
	unsigned int default_ad;

};

#endif

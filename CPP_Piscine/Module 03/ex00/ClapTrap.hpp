#ifndef CLAP_TRAP_H
#define CLAP_TRAP_H

#include <iostream>
#include <string>

class ClapTrap {

public:

    ClapTrap(std::string name);
    ~ClapTrap();

    std::string		getName(void);
    unsigned int	getHitPoints(void);
    unsigned int	getEnergyPoints(void);
    unsigned int 	getAttackDamage(void);

    void attack(const std::string& target);
    void takeDamage(unsigned int amount);
    void beRepaired(unsigned int amount);

private:

    std::string     _name;
    unsigned int    _hitPoints;
    unsigned int    _energyPoints;
    unsigned int 	_attackDamage;

};

#endif
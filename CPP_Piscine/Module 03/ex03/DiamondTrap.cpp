#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(std::string name) :	ClapTrap(name + "_clap_name"),

												ScavTrap(name),
												FragTrap(name),
												_name(name) {
	std::cout	<< "DiamondTrap constructor has been called for "
				<< name << "!" << std::endl;
	setHitPoints(FragTrap::default_hp);
	setEnergyPoints(ScavTrap::default_ep);
	setAttackDamage(FragTrap::default_ad);
}

DiamondTrap::~DiamondTrap() {
	std::cout	<< "DiamondTrap destructor has been called for "
				 << _name << "!" << std::endl;
}

std::string DiamondTrap::getName() {
	return _name;
}

void DiamondTrap::attack(const std::string& target) {
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI() {
	std::cout	<< "Yo ma name is " << _name
				<< " and ma ClapTrap name is "
				<< ClapTrap::getName() << std::endl;
}

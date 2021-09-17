#include "FragTrap.hpp"

FragTrap::FragTrap(std::string name) : ClapTrap(name) {
    std::cout	<< "FragTrap constructor has been called for "
    			<< name << "!" << std::endl;
    setHitPoints(100);
    setEnergyPoints(50);
    setAttackDamage(30);
};

FragTrap::~FragTrap() {
    std::cout	<< "FragTrap destructor has been called for "
    			<< getName() << "!" << std::endl;
}

void FragTrap::attack(const std::string target) {
    std::cout << "FragTrap " << getName() << " attacks "
              << target << ", causing " << getAttackDamage()
              << " points of damage!" << std::endl;
}

void FragTrap::highFivesGuys() {
    std::cout	<< "FragTrap " << getName()
    			<< " says: 'Hey! High Five?'" << std::endl;
}


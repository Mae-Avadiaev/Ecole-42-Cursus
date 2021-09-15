#include "ClapTrap.hpp"

ClapTrap::ClapTrap(std::string name) :	_name(name),
										_hitPoints(10),
										_energyPoints(10),
										_attackDamage(0) {
    std::cout	<< "ClapTrap constructor has been called for "
    			<< name << "!" << std::endl;
}

ClapTrap::~ClapTrap() {
    std::cout	<< "ClapTrap destructor has been called for "
    			<< _name << "!" << std::endl;
}

void ClapTrap::setHitPoints(unsigned int value) {
	_hitPoints = value;
}

void ClapTrap::setEnergyPoints(unsigned int value) {
	_energyPoints = value;
}

void ClapTrap::setAttackDamage(unsigned int value) {
	_attackDamage = value;
}

std::string	ClapTrap::getName(void) {
	return _name;
}
unsigned int ClapTrap::getHitPoints(void) {
	return _hitPoints;
};

unsigned int ClapTrap::getEnergyPoints(void) {
	return _energyPoints;
}

unsigned int ClapTrap::getAttackDamage() {
	return _attackDamage;
}

void ClapTrap::attack(const std::string& target) {
    std::cout << "ClapTrap " << _name << " attacks "
              << target << ", causing " << _hitPoints
              << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " takes "
              << amount << " points of damage!" << std::endl;
}

void ClapTrap::beRepaired(unsigned int amount) {
    std::cout << "ClapTrap " << _name << " be repaired by "
              << amount << " points!" << std::endl;
}

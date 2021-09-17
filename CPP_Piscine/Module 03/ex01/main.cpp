#include "ClapTrap.hpp"
#include "ScavTrap.hpp"

int main(void) {
    ScavTrap lehaNavalniy = ScavTrap("Leha Navalniy");
    ScavTrap petutin = ScavTrap("petutin");

    lehaNavalniy.attack(petutin.getName());
    petutin.takeDamage(lehaNavalniy.getAttackDamage());
    petutin.attack(lehaNavalniy.getName());
    lehaNavalniy.takeDamage(petutin.getAttackDamage());
    lehaNavalniy.beRepaired(lehaNavalniy.getEnergyPoints());
    lehaNavalniy.guardGate();


    return 0;
}


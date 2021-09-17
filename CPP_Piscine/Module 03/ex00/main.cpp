#include "ClapTrap.hpp"

int main(void) {
    ClapTrap georgeBush = ClapTrap("George Bush");
    ClapTrap saddamHussein = ClapTrap("Saddam Hussein");

    saddamHussein.attack(georgeBush.getName());
    georgeBush.takeDamage(saddamHussein.getAttackDamage());
    georgeBush.attack(saddamHussein.getName());
    saddamHussein.takeDamage(georgeBush.getAttackDamage());
    georgeBush.beRepaired(georgeBush.getEnergyPoints());

    return 0;
}
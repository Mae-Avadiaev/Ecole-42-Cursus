#include "ClapTrap.hpp"
#include "FragTrap.hpp"

int main(void) {
    FragTrap bur = FragTrap("Vick");
    FragTrap englishMan = FragTrap("John");

    bur.attack(englishMan.getName());
    englishMan.takeDamage(bur.getAttackDamage());
    englishMan.attack(bur.getName());
    bur.takeDamage(englishMan.getAttackDamage());
    bur.beRepaired(bur.getEnergyPoints());
    bur.highFivesGuys();

    return 0;
}


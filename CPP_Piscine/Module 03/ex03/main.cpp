#include "DiamondTrap.hpp"

int main(void) {
	printf("----------ClapTraps----------\n");
	ClapTrap georgeBush = ClapTrap("George Bush");
	ClapTrap saddamHussein = ClapTrap("Saddam Hussein");

	saddamHussein.attack(georgeBush.getName());
	georgeBush.takeDamage(saddamHussein.getAttackDamage());
	georgeBush.attack(saddamHussein.getName());
	saddamHussein.takeDamage(georgeBush.getAttackDamage());
	georgeBush.beRepaired(georgeBush.getEnergyPoints());

	printf("----------ScavTraps----------\n");
	ScavTrap lehaNavalniy = ScavTrap("Leha Navalniy");
	ScavTrap petutin = ScavTrap("petutin");

	lehaNavalniy.attack(petutin.getName());
	petutin.takeDamage(lehaNavalniy.getAttackDamage());
	petutin.attack(lehaNavalniy.getName());
	lehaNavalniy.takeDamage(petutin.getAttackDamage());
	lehaNavalniy.beRepaired(lehaNavalniy.getEnergyPoints());
	lehaNavalniy.guardGate();


	printf("----------FragTraps----------\n");
    FragTrap bur = FragTrap("Vick");
    FragTrap englishMan = FragTrap("John");

    bur.attack(englishMan.getName());
    englishMan.takeDamage(bur.getAttackDamage());
    englishMan.attack(bur.getName());
    bur.takeDamage(englishMan.getAttackDamage());
    bur.beRepaired(bur.getEnergyPoints());
    bur.highFivesGuys();


	printf("----------DiamondTraps----------\n");
	DiamondTrap drake = DiamondTrap("Drake");
	DiamondTrap kim = DiamondTrap("Kim");

	drake.attack(kim.getName());
	kim.takeDamage(drake.getAttackDamage());
	kim.attack(drake.getName());
	drake.takeDamage(kim.getAttackDamage());
	drake.beRepaired(drake.getEnergyPoints());
	drake.highFivesGuys();
	drake.guardGate();
	drake.whoAmI();

	printf("----------Destructors----------\n");
    return 0;
}


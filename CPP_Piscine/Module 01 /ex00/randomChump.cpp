#include "Zombie.hpp"

void randomChump(std::string name) {
	Zombie *bob = newZombie(name);
	bob->announce();
	delete(bob);
}
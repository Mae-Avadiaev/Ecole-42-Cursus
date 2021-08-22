#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>

class Zombie {

public:

	void announce(void) const;
	Zombie* newZombie(std::string name);

	Zombie(std::string name);
	~Zombie(void);

private:

	std::string _name;

};

void randomChump(std::string name);
Zombie* newZombie(std::string name);

#endif

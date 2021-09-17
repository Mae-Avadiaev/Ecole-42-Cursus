#ifndef ZOMBIE_HPP
#define ZOMBIE_HPP

#include <iostream>
#include <stdlib.h>

class Zombie {

public:

	void announce(void) const;
	void setName(std::string name);

	Zombie(void);
	~Zombie(void);

private:

	std::string _name;

};

void randomChump(std::string name);
Zombie* zombieHorde(int N, std::string name);

#endif

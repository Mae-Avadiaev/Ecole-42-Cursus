#include "Zombie.hpp"

Zombie::Zombie(void) {
	;
}

Zombie::~Zombie() {
	std::cout << this->_name << " has rotten away!" << std::endl;
}

void Zombie::announce() const {
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::setName(std::string name) {
	this->_name = name;
}





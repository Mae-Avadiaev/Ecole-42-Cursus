#include "Zombie.hpp"

Zombie::Zombie(std::string name) : _name(name) {
	;
}

Zombie::~Zombie() {
	std::cout << this->_name << " has rotten away!" << std::endl;
}

void Zombie::announce() const {
	std::cout << this->_name << " BraiiiiiiinnnzzzZ..." << std::endl;
}





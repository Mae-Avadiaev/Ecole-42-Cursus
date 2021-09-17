#include "Karen.hpp"

int Karen::calc_level(std::string level) {
	int lvl = 0;

	lvl = ((!level.compare("DEBUG") * 1)
		   + (!level.compare("INFO") * 2)
		   + (!level.compare("WARNING") * 3)
		   + (!level.compare("ERROR") * 4)
		   + (!level.compare("EXIT") * 5));
	return lvl;
}

void Karen::complain(std::string level) {
	int lvl;

	switch (lvl = calc_level(level)) {
		case 0:
			std::cout << "I can't do anything like that!" << std::endl;
			break;
		case 1:
			this->debug();
		case 2:
			this->info();
		case 3:
			this->warning();
		case 4:
			this->error();
		case 5:
			;
	}
}

void Karen::debug(void) {
	std::cout << "[ DEBUG ]" << std::endl;
	std::cout << "I love to get extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				 "I just love it!" << std::endl;
}

void Karen::info(void) {
	std::cout << "[ INFO ]" << std::endl;
	std::cout << "I cannot believe adding extra bacon cost more money. "
				 "You don’t put enough! If you did I would not have to ask for it!"
			  << std::endl;
}

void Karen::warning(void) {
	std::cout << "[ WARNING ]" << std::endl;
	std::cout << "I think I deserve to have some extra bacon for free. "
				 "I’ve been coming here for years and you just started working "
				 "here last month." << std::endl;
}

void Karen::error(void) {
	std::cout << "[ ERROR ]" << std::endl;
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}



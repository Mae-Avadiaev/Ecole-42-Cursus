#include "Karen.hpp"

Karen::Karen() {
	init_func_arr();
}

void Karen::init_func_arr() {
	this->func_arr[0] = &Karen::debug;
	this->func_arr[1] = &Karen::info;
	this->func_arr[2] = &Karen::warning;
	this->func_arr[3] = &Karen::error;
}

int Karen::calc_level(std::string level) {
	int lvl = 0;

	lvl = ((!level.compare("DEBUG") * 1)
				+ (!level.compare("INFO") * 2)
					+ (!level.compare("WARNING") * 3)
						+ (!level.compare("ERROR") * 4));
	if (lvl == 0 && !!level.compare("EXIT"))
		std::cout << "I can't complain on this level!" << std::endl;
	return lvl;
}

void Karen::complain(std::string level) {
	int lvl = 0;

	if ((lvl = calc_level(level)) != 0) {
		(this->*func_arr[lvl - 1])();
	}
}

void Karen::debug(void) {
	std::cout << "I love to get extra bacon for my "
				 "7XL-double-cheese-triple-pickle-special-ketchup burger. "
				 "I just love it!" << std::endl;
}

void Karen::info(void) {
	std::cout << "I cannot believe adding extra bacon cost more money. "
				 "You don’t put enough! If you did I would not have to ask for it!"
				 << std::endl;
}

void Karen::warning(void) {
	std::cout << "I think I deserve to have some extra bacon for free. "
				 "I’ve been coming here for years and you just started working "
				 "here last month." << std::endl;
}

void Karen::error(void) {
	std::cout << "This is unacceptable, I want to speak to the manager now." << std::endl;
}



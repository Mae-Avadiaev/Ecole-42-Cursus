#include "RobotomyRequestForm.hpp"
#include <unistd.h>

RobotomyRequestForm::RobotomyRequestForm(std::string target) :	Form("Robotomy Request", 72, 45),
																_target(target) {}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) :	Form("Robotomy Request", 72, 45),
																				_target(other._target) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	if (this != &other) {
		_target = other._target;
		setIsSigned(other.isSigned());
	}
	return *this;
}

void RobotomyRequestForm::toWork() const {
	sleep(1);
	std::cout << "Starting robotomy process..." << std::endl;
	sleep(1);
	std::cout << "Drrrrrr...." << std::endl;
	sleep(2);
	std::cout << "Wwwwwwww...." << std::endl;
	sleep(3);
	std::cout << "Zhhhhhhh...." << std::endl;
	sleep(4);
	std::cout << "Please, wait some time for results..." << std::endl;
	sleep(5);
	if ((std::rand() % 2) == 0)
		std::cout	<< "Yeah! " <<_target << " has been SUCCESSFULLY robotized!"
					<< std::endl;
	else
		std::cout 	<< "Sorry, " <<_target << " robatization has been FAILED!"
					<< std::endl;

}
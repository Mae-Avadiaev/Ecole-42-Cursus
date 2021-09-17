#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main() {

	try {
		Bureaucrat arny = Bureaucrat("Arnold Schwarzenegger", 5);

		Form *newShrubberyHill = new ShrubberyCreationForm("Kardashian_Ave");
		std::cout << *newShrubberyHill << std::endl;
		arny++;
		newShrubberyHill->beSigned(arny);
		std::cout << *newShrubberyHill << std::endl;
		newShrubberyHill->execute(arny);

		Form *hunterThompsonRobotization = new RobotomyRequestForm("Hunter Thompson");
		std::cout << *hunterThompsonRobotization << std::endl;
		arny++;
		hunterThompsonRobotization->beSigned(arny);
		std::cout << *hunterThompsonRobotization << std::endl;
		hunterThompsonRobotization->execute(arny);

		Form *pardonforBurroughs = new PresidentialPardonForm("William Seward Burroughs");
		std::cout << *pardonforBurroughs<< std::endl;
		arny++;
		pardonforBurroughs->beSigned(arny);
		std::cout << *pardonforBurroughs<< std::endl;
		pardonforBurroughs->execute(arny);

		delete newShrubberyHill;
		delete hunterThompsonRobotization;
		delete pardonforBurroughs;

	}
	catch (Form::GradeTooHighException &ex1) {
		std::cout << ex1 << std::endl;
	}
	catch (Form::GradeTooLowException &ex2) {
		std::cout << ex2 << std::endl;
	}
	catch (std::exception &ex3) {
		std::cout	<< ex3.what() << " occurred!" << std::endl;
	}

	return 0;
}
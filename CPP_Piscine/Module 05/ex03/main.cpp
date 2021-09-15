#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main() {

	try {

		Intern *randomIntern = new Intern();

//		Form *someForm = randomIntern->makeForm("this form, you idiot", "!!!");
		Form *robotSeana = randomIntern->makeForm("robotomy request", "John Seana");

		Intern *anotherRandomIntern = randomIntern;
		Intern *anotherRandomIntern2 = new Intern(*randomIntern);

		Form *shrubberyHill = anotherRandomIntern->makeForm("shrubbery creation", "Kazan City");
		Form *lehaNavalny = anotherRandomIntern2->makeForm("presidential pardon", "Leha Navalny");

		std::cout	<< *robotSeana << std::endl;
		std::cout	<< *shrubberyHill << std::endl;
		std::cout	<< *lehaNavalny << std::endl;

//		delete someForm;
		delete robotSeana;
		delete randomIntern;
		delete shrubberyHill;
		delete lehaNavalny;
		delete anotherRandomIntern2;

	}
	catch (Form::GradeTooHighException &ex1) {
		std::cout << ex1 << std::endl;
	}
	catch (Form::GradeTooLowException &ex2) {
		std::cout << ex2 << std::endl;
	}
	catch (Intern::UnknownFormTypeException &ex4) {
		std::cout << ex4 << std::endl;
	}
	catch (std::exception &ex3) {
		std::cout	<< ex3.what() << " occurred!" << std::endl;
	}

	return 0;
}
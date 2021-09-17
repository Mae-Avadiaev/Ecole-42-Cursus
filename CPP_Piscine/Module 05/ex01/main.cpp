#include "Bureaucrat.hpp"
#include "Form.hpp"

int main() {

	try {
		Bureaucrat kennedy = Bureaucrat("John Kennedy", 21);
		Form weChooseToGoToTheMoon = Form("We Choose to Go to The Moon!", 20, 20);
		std::cout << weChooseToGoToTheMoon << std::endl;
//		weChooseToGoToTheMoon.beSigned(kennedy);
		kennedy++;
		weChooseToGoToTheMoon.beSigned(kennedy);
		std::cout << weChooseToGoToTheMoon << std::endl;
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
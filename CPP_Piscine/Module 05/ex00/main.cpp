#include "Bureaucrat.hpp"

int main() {

	try {
		Bureaucrat mister = Bureaucrat("Mister", 160);
		mister--;
		std::cout	<< mister << std::endl;
		mister++; mister++;
		std::cout	<< mister << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &ex1) {
		std::cout << ex1 << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException &ex2) {
		std::cout << ex2 << std::endl;
	}
	catch (std::exception &ex3) {
		std::cout	<< ex3.what() << " occurred!" << std::endl;
	}

	return 0;
}
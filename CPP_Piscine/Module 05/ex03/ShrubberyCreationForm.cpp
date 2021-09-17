#include "ShrubberyCreationForm.hpp"
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) :	Form("Shrubbery Creation", 145, 137),
																	_target(target) {}

ShrubberyCreationForm::ShrubberyCreationForm(
		const ShrubberyCreationForm &other) : Form("Shrubbery Creation", 145, 137),
											  _target(other._target) {}

ShrubberyCreationForm::~ ShrubberyCreationForm() {}

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	if (this != &other) {
		_target = other._target;
		setIsSigned(other.isSigned());
	}
	return *this;
}

void ShrubberyCreationForm::toWork() const {
	sleep(1);
	std::cout << "Creation has been started!" << std::endl;
	std::string fileName = _target + "_shrubbery";
	std::ofstream outfile(fileName);
	sleep(3);
	std::cout << "Platform has been created!" << std::endl;
	sleep(3);
	std::cout << "Seed has been planted, growing in fast mode..." << std::endl;
	sleep(6);
	outfile << "                                   # #### ####\n"
			   "                                ### \\/#|### |/####\n"
			   "                               ##\\/#/ \\||/##/_/##/_#\n"
			   "                             ###  \\/###|/ \\/ # ###\n"
			   "                           ##_\\_#\\_\\## | #/###_/_####\n"
			   "                          ## #### # \\ #| /  #### ##/##\n"
			   "                           __#_--###`  |{,###---###-~\n"
			   "                                    \\ }{\n"
			   "                                      }}{\n"
			   "                                      }}{\n"
			   "                                 ejm  {{}\n"
			   "                                , -=-~{ .-^- _\n"
			   "                                      `}\n"
			   "                                       {"
			<< std::endl;
	std::cout << "Shrubbery has been SUCCESSFULLY created!" << std::endl;
	outfile.close();
}
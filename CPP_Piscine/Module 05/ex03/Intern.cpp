#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

Intern::UnknownFormTypeException::UnknownFormTypeException(	const std::string msg,
															 const std::string file,
															 int line,
															 const std::string func,
															 const std::string info ) :
		_msg(msg),
		_file(file),
		_line(line),
		_func(func),
		_info(info) {}

const std::string Intern::UnknownFormTypeException::getFile() const {
	return _file;
}

int Intern::UnknownFormTypeException::getLine() const {

	return  _line;
}

const std::string Intern::UnknownFormTypeException::getFunc() const {
	return _func;
}

const std::string Intern::UnknownFormTypeException::getInfo() const {
	return _info;
}

const std::string Intern::UnknownFormTypeException::getMsg() const {
	return _msg;
}

std::ostream& operator<<(std::ostream &out, Intern::UnknownFormTypeException &ex) {
	out		<< ex.getFile() << ":" << ex.getLine()
			   << ": error: " << ex.getMsg() << std::endl
			   << "In method: " << ex.getFunc();
	return out;
}

Intern::Intern() {
	_formCreationArray[0] = &Intern::makeSrubberyCreationForm;
	_formCreationArray[1] = &Intern::makeRobotomyRequestForm;
	_formCreationArray[2] = &Intern::makePresidentialPardonForm;
}

Intern::Intern(const Intern &other) {
	std::copy(std::begin(other._formCreationArray),
			  std::end(other._formCreationArray),
			  std::begin(_formCreationArray));
}

Intern::~Intern() {}

Intern& Intern::operator=(const Intern &other) {
	(void)other;
    return *this;
}

Form* Intern::makeSrubberyCreationForm(std::string target) {
	return new ShrubberyCreationForm(target);
}

Form* Intern::makeRobotomyRequestForm(std::string target) {
	return new RobotomyRequestForm(target);
}

Form* Intern::makePresidentialPardonForm(std::string target) {
	return new PresidentialPardonForm(target);
}

Form* Intern::makeForm(std::string formName, std::string formTarget) {
	int formType = 0;
	formType = 	(formName == "shrubbery creation") * 1 +
				(formName == "robotomy request") * 2 +
				(formName == "presidential pardon") * 3;
	if (!formType) {
		throw UnknownFormTypeException(		UFT,
										   __FILE__,
										   __LINE__,
										   __FUNCTION__,
										   ""	);
	} else {
		std::cout << "Intern creates " << formName << "form!" << std::endl;
		return (this->*_formCreationArray[formType - 1])(formTarget);
	}
}


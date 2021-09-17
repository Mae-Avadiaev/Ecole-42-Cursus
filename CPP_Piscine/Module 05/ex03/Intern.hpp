#ifndef INTERN_HPP
#define INTERN_HPP 

#include <iostream>
#include <string>
#include "Form.hpp"

#define UFT "Ssssory Sir... We haven't been taught this type of forms..."

class Intern {

	typedef Form*(Intern::*cFunc)(std::string);

public:

	class UnknownFormTypeException : public std::exception {

	public:

		UnknownFormTypeException(	const std::string msg,
								 	const std::string file,
								 	int line,
								 	const std::string func,
								 	const std::string info );
		~UnknownFormTypeException() _NOEXCEPT {};

		const std::string getMsg() const;
		const std::string getFile() const;
		int getLine() const;
		const std::string getFunc() const;
		const std::string getInfo() const;

	private:

		const std::string _msg;
		const std::string _file;
		int _line;
		const std::string _func;
		const std::string _info;

	};

    Intern();
    Intern(const Intern &other);
    ~Intern();
    Intern& operator=(const Intern &other);

	Form* makeForm(std::string formName, std::string formTarget);

private:

	cFunc	_formCreationArray[3];

	Form* makeSrubberyCreationForm(std::string target);
	Form* makeRobotomyRequestForm(std::string target);
	Form* makePresidentialPardonForm(std::string target);

};

std::ostream& operator<<(std::ostream &out, Intern::UnknownFormTypeException &ex);

#endif
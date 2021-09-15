#ifndef FORM_HPP
#define FORM_HPP

#include <exception>
#include <iostream>
#include <string>
#include "Bureaucrat.hpp"

#define GTLTCSF "Hobos from the streets can't sign Forms!"
#define GTLTCEF "A hobo can't execute this Form!"

#define GTHTCSF "God is too busy to sign such insignificant form!"
#define GTHTCEF "God is too busy to execute such insignificant form!"

class Form {

public:

	class GradeTooLowException : public std::exception {

	public:

		GradeTooLowException(	const std::string msg,
								 const std::string file,
								 int line,
								 const std::string func,
								 const std::string info );
		~GradeTooLowException() _NOEXCEPT {};

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

	class GradeTooHighException : public std::exception {

	public:

		GradeTooHighException(	const std::string msg,
								  const std::string file,
								  int line,
								  const std::string func,
								  const std::string info );
		~GradeTooHighException() _NOEXCEPT {};

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

	Form(std::string name, int gradeToSign, int gradeToExecute);
	Form(const Form &other);
	~Form();
	Form& operator=(const Form &other);

	const std::string getName() const;
	bool isSigned() const;
	int getGradeToSign() const;
	int getGradeToExecute() const;

	void beSigned(const Bureaucrat &b);

private:

	const std::string _name;
	bool _isSigned;
	const int _gradeToSign;
	const int _gradeToExecute;

};

std::ostream& operator<<(std::ostream &out, Form &f);
std::ostream& operator<<(std::ostream &out, Form::GradeTooLowException &ex);
std::ostream& operator<<(std::ostream &out, Form::GradeTooHighException &ex);

#endif
#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <exception>
#include <iostream>
#include <string>

#define GTH "You trying to make a GOD out of a Bureaucrat!"
#define GTL "You trying to leave Bureaucrat on the street!"

#define GTLTS "This Clerk's grade is too low to sign this Form!"

class Form;

class Bureaucrat {

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

	Bureaucrat(const std::string name, int grade);
	Bureaucrat(const Bureaucrat &other);
	~Bureaucrat();
	Bureaucrat& operator=(const Bureaucrat &other);

	Bureaucrat operator++(int);
	Bureaucrat operator--(int);

	std::string getName() const;
	int getGrade() const;

	void signForm(int gradeToSign, std::string formName) const;
	void executeForm(const Form &form);

private:

	const std::string	_name;
	int					_grade;

};

std::ostream& operator<<(std::ostream &out, Bureaucrat &b);
std::ostream& operator<<(std::ostream &out, Bureaucrat::GradeTooLowException &ex);
std::ostream& operator<<(std::ostream &out, Bureaucrat::GradeTooHighException &ex);

#endif
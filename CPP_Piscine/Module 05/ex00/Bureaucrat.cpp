#include "Bureaucrat.hpp"

//----------Bureaucrat::GradeTooLowException----------

Bureaucrat::GradeTooLowException::GradeTooLowException(	const std::string msg,
											   const std::string file,
											   int line,
											   const std::string func,
											   const std::string info ) :
		_msg(msg),
		_file(file),
		_line(line),
		_func(func),
		_info(info) {}

const std::string Bureaucrat::GradeTooLowException::getFile() const {
	return _file;
}

int Bureaucrat::GradeTooLowException::getLine() const {

	return  _line;
}

const std::string Bureaucrat::GradeTooLowException::getFunc() const {
	return _func;
}

const std::string Bureaucrat::GradeTooLowException::getInfo() const {
	return _info;
}

const std::string Bureaucrat::GradeTooLowException::getMsg() const {
	return _msg;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat::GradeTooLowException &ex) {
	out		<< ex.getFile() << ":" << ex.getLine()
			   << ": error: " << ex.getMsg() << std::endl
			   << "In method: " << ex.getFunc();
	return out;
}

//----------Bureaucrat::GradeTooHighException----------

Bureaucrat::GradeTooHighException::GradeTooHighException(	const std::string msg,
												 const std::string file,
												 int line,
												 const std::string func,
												 const std::string info ) :
		_msg(msg),
		_file(file),
		_line(line),
		_func(func),
		_info(info) {}

const std::string Bureaucrat::GradeTooHighException::getFile() const {
	return _file;
}

int Bureaucrat::GradeTooHighException::getLine() const {

	return  _line;
}

const std::string Bureaucrat::GradeTooHighException::getFunc() const {
	return _func;
}

const std::string Bureaucrat::GradeTooHighException::getInfo() const {
	return _info;
}

const std::string Bureaucrat::GradeTooHighException::getMsg() const {
	return _msg;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat::GradeTooHighException &ex) {
	out		<< ex.getFile() << ":" << ex.getLine()
			   << ": error: " << ex.getMsg() << std::endl
			   << "In method: " << ex.getFunc();
	return out;
}

//----------Bureaucrat----------

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name) {
	if (grade < 1)
		throw GradeTooHighException(	GTH,
							   			__FILE__,
							   			__LINE__,
							   			__FUNCTION__,
			 							""	);
	else if (grade > 150)
		throw GradeTooLowException(		GTL,
							   			__FILE__,
							   			__LINE__,
							   			__FUNCTION__,
			 							""	);
	else
		_grade = grade;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) :
	_name(other._name),
	_grade(other._grade) {}

Bureaucrat::~Bureaucrat() {}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &other) {
	if (this != &other) {
		_grade = other._grade;
	}
	return *this;
}

Bureaucrat Bureaucrat::operator++(int) {
	if ((_grade - 1) < 1)
		throw GradeTooHighException(	GTH,
										__FILE__,
										__LINE__,
										__FUNCTION__,
										""	);
	Bureaucrat temp = *this;
	this->_grade -= 1;
	return temp;
}

Bureaucrat Bureaucrat::operator--(int) {
	if ((_grade + 1) > 150)
		throw GradeTooLowException(		GTL,
										__FILE__,
										__LINE__,
										__FUNCTION__,
										""	);
	Bureaucrat temp = *this;
	this->_grade += 1;
	return temp;
}

std::string Bureaucrat::getName() const {
	return _name;
}

int Bureaucrat::getGrade() const {
	return _grade;
}

std::ostream& operator<<(std::ostream &out, Bureaucrat &b) {
	out << b.getName() << ", bureaucrat grade " << b.getGrade();
	return out;
}

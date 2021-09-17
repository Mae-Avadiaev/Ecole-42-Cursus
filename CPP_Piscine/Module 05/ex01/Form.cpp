#include "Form.hpp"

//----------Form::GradeTooLowException----------

Form::GradeTooLowException::GradeTooLowException(	const std::string msg,
											   const std::string file,
											   int line,
											   const std::string func,
											   const std::string info ) :
		_msg(msg),
		_file(file),
		_line(line),
		_func(func),
		_info(info) {}

const std::string Form::GradeTooLowException::getFile() const {
	return _file;
}

int Form::GradeTooLowException::getLine() const {

	return  _line;
}

const std::string Form::GradeTooLowException::getFunc() const {
	return _func;
}

const std::string Form::GradeTooLowException::getInfo() const {
	return _info;
}

const std::string Form::GradeTooLowException::getMsg() const {
	return _msg;
}

std::ostream& operator<<(std::ostream &out, Form::GradeTooLowException &ex) {
	out		<< ex.getFile() << ":" << ex.getLine()
			   << ": error: " << ex.getMsg() << std::endl
			   << "In method: " << ex.getFunc();
	return out;
}

//----------Form::GradeTooHighException----------

Form::GradeTooHighException::GradeTooHighException(	const std::string msg,
												 const std::string file,
												 int line,
												 const std::string func,
												 const std::string info ) :
		_msg(msg),
		_file(file),
		_line(line),
		_func(func),
		_info(info) {}

const std::string Form::GradeTooHighException::getFile() const {
	return _file;
}

int Form::GradeTooHighException::getLine() const {

	return  _line;
}

const std::string Form::GradeTooHighException::getFunc() const {
	return _func;
}

const std::string Form::GradeTooHighException::getInfo() const {
	return _info;
}

const std::string Form::GradeTooHighException::getMsg() const {
	return _msg;
}

std::ostream& operator<<(std::ostream &out, Form::GradeTooHighException &ex) {
	out		<< ex.getFile() << ":" << ex.getLine()
			   << ": error: " << ex.getMsg() << std::endl
			   << "In method: " << ex.getFunc();
	return out;
}

//----------Form----------

Form::Form(std::string name, int gradeToSign, int gradeToExecute) :
	_name(name),
	_isSigned(false),
	_gradeToSign(gradeToSign),
	_gradeToExecute(gradeToExecute) {
	if (_gradeToSign > 150)
		throw GradeTooLowException(GTLTCSF,
								   __FILE__,
								   __LINE__,
								   __FUNCTION__,
								   ""	);
	else if (_gradeToSign < 1)
		throw GradeTooHighException(GTHTCSF,
									__FILE__,
									__LINE__,
									__FUNCTION__,
									""	);

	if (_gradeToExecute > 150)
		throw GradeTooLowException(GTLTCEF,
								   __FILE__,
								   __LINE__,
								   __FUNCTION__,
								   ""	);
	else if (_gradeToExecute < 1)
		throw GradeTooHighException(GTHTCEF,
									__FILE__,
									__LINE__,
									__FUNCTION__,
									""	);

}

Form::Form(const Form &other) :	_name(other._name),
								_isSigned(false),
								_gradeToSign(other._gradeToSign),
								_gradeToExecute(other._gradeToExecute) {}

Form::~Form() {}

Form& Form::operator=(const Form &other) {
	if (this != &other)
		_isSigned = other._isSigned;
	return *this;
}

const std::string Form::getName() const {
	return _name;
}

bool Form::isSigned() const {
	return _isSigned;
}

int Form::getGradeToSign() const {
	return _gradeToSign;
}

int Form::getGradeToExecute() const {
	return _gradeToExecute;
}

void Form::beSigned(const Bureaucrat &b) {
	b.signForm(_gradeToSign, _name);
	if (b.getGrade() > _gradeToSign)
		throw GradeTooLowException(	GTLTS,
							  		__FILE__,
							  		__LINE__,
							  		__FUNCTION__,
							  		"" );
	_isSigned = true;
}

std::ostream& operator<<(std::ostream &out, Form &f) {
	out		<< "The Form " << f.getName() << " is";
	if (!f.isSigned())
		out << " NOT";
	out		<< " SIGNED by at least GRADE " << f.getGradeToSign()
			<< " and can be EXECUTED by at least grade " << f.getGradeToExecute();
	return out;
}
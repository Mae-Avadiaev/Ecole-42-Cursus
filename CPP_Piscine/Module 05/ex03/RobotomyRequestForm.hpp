#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP 

#include "Form.hpp"

class RobotomyRequestForm : public Form {

public:

    RobotomyRequestForm(std::string target);
    RobotomyRequestForm(const RobotomyRequestForm &other);
    ~RobotomyRequestForm();
    RobotomyRequestForm& operator=(const RobotomyRequestForm &other);

	void toWork() const;

private:

	std::string _target;

};

#endif 

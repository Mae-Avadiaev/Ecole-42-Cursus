#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP 

#include "Form.hpp"

class PresidentialPardonForm : public Form {

public:

    PresidentialPardonForm(std::string target);
    PresidentialPardonForm(const PresidentialPardonForm &other);
    ~PresidentialPardonForm();
    PresidentialPardonForm& operator=(const PresidentialPardonForm &other);

	void toWork() const;

private:

	std::string _target;

};

#endif 

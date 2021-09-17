#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(std::string target) :	Form("Presidential Pardon", 25, 5),
																		_target(target) {

}

PresidentialPardonForm::PresidentialPardonForm(
		const PresidentialPardonForm &other) : Form("Presidential Pardon", 25, 5),
											   _target(other._target) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	if (this != &other) {
		_target = other._target;
		setIsSigned(other.isSigned());
	}
	return *this;
}

void PresidentialPardonForm::toWork() const {
	sleep(1);
	std::cout	<< _target << " has been pardoned by Zafod Beeblebrox."
				<< std::endl;
}
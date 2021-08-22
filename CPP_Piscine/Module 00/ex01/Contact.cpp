#include "ilovecpp_phonebook.hpp"

void	Contact::set_cont(int index) {
	std::cout << "First name:" << std::endl;
	getline(std::cin, this->_first_name);
	std::cout << "Last name:" << std::endl;
	getline(std::cin, this->_last_name);
	std::cout << "Nickname:" << std::endl;
	getline(std::cin, this->_nickname);
	std::cout << "Phone number:" << std::endl;
	getline(std::cin, this->_phone_number);
	std::cout << "Darkest secret:" << std::endl;
	getline(std::cin, this->_darkest_secret);
	this->_index = index;
	std::cout << "Contact added successfully!" << std::endl;
};

std::string	Contact::get_cont(std::string field) const {
	if (!field.compare("first_name"))
		return this->_first_name;
	else if (!field.compare("last_name"))
		return this->_last_name;
	else if (!field.compare("nickname"))
		return this->_nickname;
	else if (!field.compare("phone_number"))
		return this->_phone_number;
	else
		return this->_darkest_secret;
}

int	Contact::get_index() const {
	return this->_index;
}
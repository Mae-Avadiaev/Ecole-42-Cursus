#include "ilovecpp_phonebook.hpp"

void	Contact::set_cont(int index) {
	std::cout << "First name:" << std::endl;
	getline(std::cin, this->first_name);
	std::cout << "Last name:" << std::endl;
	getline(std::cin, this->last_name);
	std::cout << "Nickname:" << std::endl;
	getline(std::cin, this->nickname);
	std::cout << "Phone number:" << std::endl;
	getline(std::cin, this->phone_number);
	std::cout << "Darkest secret:" << std::endl;
	getline(std::cin, this->darkest_secret);
	this->index = index;
	std::cout << "Contact added successfully!" << std::endl;
};

std::string	Contact::get_cont(std::string field) const {
	if (!field.compare("first_name"))
		return this->first_name;
	else if (!field.compare("last_name"))
		return this->last_name;
	else if (!field.compare("nickname"))
		return this->nickname;
	else if (!field.compare("phone_number"))
		return this->phone_number;
	else
		return this->darkest_secret;
}

int	Contact::get_index() const {
	return this->index;
}
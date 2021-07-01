#include "ilovecpp_phonebook.hpp"

Phonebook::Phonebook() {
	this->cont_amount = 0;
}

void	Phonebook::add(int index) {
	this->contacts[index].set_cont(index);
	this->cont_amount += 1;
}

void	Phonebook::print_all_conts() const {
	for (int i = 0; i < this->cont_amount; i++)
	{
		std::cout << '|' << std::setw(10) << this->contacts[i].get_index() + 1;
		std::cout << '|' << std::setw(10) << truncate(this->contacts[i].get_cont(
				"first_name"), 10, ".");
		std::cout << '|' << std::setw(10) << truncate(this->contacts[i].get_cont(
				"last_name"), 10, ".");
		std::cout << '|' << std::setw(10) << truncate(this->contacts[i].get_cont(
				"nickname"), 10, ".") << '|' << std::endl;
	}
}

void	Phonebook::reveal_contact(int index) const {
	if (index > this->cont_amount - 1)
		std::cout << "Contact not found!" << std::endl;
	else {
		std::cout << this->contacts[index].get_cont("first_name") << std::endl;
		std::cout << this->contacts[index].get_cont("last_name") << std::endl;
		std::cout << this->contacts[index].get_cont("nickname") << std::endl;
		std::cout << this->contacts[index].get_cont("phone_number") << std::endl;
		std::cout << this->contacts[index].get_cont("darkest_secret") << std::endl;
	}

}
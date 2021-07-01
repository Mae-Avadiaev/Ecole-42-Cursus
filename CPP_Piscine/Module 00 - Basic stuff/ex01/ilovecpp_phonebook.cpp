#include "ilovecpp_phonebook.hpp"

std::string	truncate(std::string str, unsigned int trunc, std::string end_seq) {
	if (str.length() > trunc)
		return str.substr(0, std::max((10 - (int)end_seq.length()), 0)) + end_seq;

	return str;
}

int main(void) {

	std::string	command;
	Phonebook	book;
	std::string	snumber;
	int			inumber = -1;


	while (std::getline(std::cin, command)) {
		if (command.compare("EXIT") == 0) {
			break;
		}
		if (command.compare("ADD") == 0) {
			book.cont_amount = std::min(7, book.cont_amount);
			book.add(book.cont_amount);
		} else if (command.compare("SEARCH") == 0) {
			book.print_all_conts();
			std::cout << "Please, type number of the contact:" << std::endl;
			getline(std::cin, snumber);
			while ((sscanf(snumber.c_str(), "%d", &inumber) != 1)
			|| inumber <= 0
			|| inumber > 8) {
				std::cout << "Wrong number! Please type 1 to 8" << std::endl;
				getline(std::cin, snumber);
			}
			book.reveal_contact(inumber - 1);
		}
	}
	std::cout << "Goodbye!" << std::endl;
	return 0;
}
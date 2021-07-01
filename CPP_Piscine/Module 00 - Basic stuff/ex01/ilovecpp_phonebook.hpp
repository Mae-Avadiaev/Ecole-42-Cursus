#ifndef ILOVECPP_PHONEBOOK_H
#define ILOVECPP_PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>

class	Contact {
private:
	std::string	first_name;
	std::string	last_name;
	std::string	nickname;
	std::string	phone_number;
	std::string	darkest_secret;
	int			index;

public:
	void set_cont(int index);
	std::string get_cont(std::string field) const;
	int			get_index(void) const;
};

class	Phonebook {
private:
	Contact	contacts[8];

public:
	int		cont_amount;

	Phonebook(void);

	void		add(int index);
	void	print_all_conts(void)		const;
	void	reveal_contact(int index)	const;

};

std::string	truncate(std::string str, unsigned int trunc, std::string end_seq);

#endif
#ifndef ILOVECPP_PHONEBOOK_H
#define ILOVECPP_PHONEBOOK_H

#include <iostream>
#include <string>
#include <iomanip>

class	Contact {

public:

	void set_cont(int index);
	std::string get_cont(std::string field) const;
	int			get_index(void) const;

private:

	std::string	_first_name;
	std::string	_last_name;
	std::string	_nickname;
	std::string	_phone_number;
	std::string	_darkest_secret;
	int			_index;

};

class	Phonebook {

public:

	int		cont_amount;

	Phonebook(void);

	void		add(int index);
	void	print_all_conts(void)		const;
	void	reveal_contact(int index)	const;

private:

	Contact	_contacts[8];

};

std::string	truncate(std::string str, unsigned int trunc, std::string end_seq);

#endif
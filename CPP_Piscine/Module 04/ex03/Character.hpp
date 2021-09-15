#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include "ICharacter.hpp"
#include "AMateria.hpp"

class Character : public ICharacter {

public:

	Character(std::string name);
	Character(const Character& other);
	~Character();
	Character& operator=(const Character &other);

	std::string const & getName() const;

	void equip(AMateria* m);
	void unequip(int idx);
	void use(int idx, ICharacter& target);

private:

	std::string _name;
	AMateria *_inventory[4];

};

#endif
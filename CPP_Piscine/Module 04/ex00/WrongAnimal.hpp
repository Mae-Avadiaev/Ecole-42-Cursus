#ifndef WRONGANIMAL_HPP
#define WRONGANIMAL_HPP

#include <iostream>
#include <string>

class WrongAnimal {

public:

	WrongAnimal();
	WrongAnimal(const WrongAnimal &other);
	~WrongAnimal();
	WrongAnimal& operator=(const WrongAnimal &other);

	std::string getType() const;
	void setType(std::string value);

	void makeSound() const;

protected:

	std::string type;

};

#endif

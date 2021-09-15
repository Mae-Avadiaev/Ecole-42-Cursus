#ifndef ANIMAL_HPP
#define ANIMAL_HPP

#include <iostream>
#include <string>
#include "Brain.hpp"

class Animal {

public:

	Animal();
	Animal(const Animal &other);
	virtual ~Animal();
	Animal& operator=(const Animal &other);

	std::string getType() const;
	void setType(std::string value);

	virtual void makeSound() const = 0;

protected:

	std::string type;

};

#endif
#ifndef Dog_HPP
#define Dog_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Dog : public Animal {

public:

	Dog();
	Dog(const Dog& other);
	virtual ~Dog();
	Dog& operator=(const Dog& other);

	void makeSound() const;

private:

	Brain *brain;

};

#endif
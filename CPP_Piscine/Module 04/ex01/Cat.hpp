#ifndef CAT_HPP
#define CAT_HPP

#include "Animal.hpp"
#include "Brain.hpp"

class Cat : public Animal {

public:

	Cat();
	Cat(const Cat& other);
	virtual ~Cat();
	Cat& operator=(const Cat &other);

	void makeSound() const;

	void captureFirstIdea(const std::string firstIdea);
	std::string revealFirstIdea() const;

private:

	Brain* brain;

};

#endif
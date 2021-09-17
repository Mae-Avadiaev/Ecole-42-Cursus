#include "Animal.hpp"
#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongAnimal.hpp"
#include "WrongCat.hpp"

int main(void) {

	const Animal* meta = new Animal();
	const Animal* j = new Dog();
	const Animal* i = new Cat();

	std::cout << j->getType() << " " << std::endl;
	std::cout << i->getType() << " " << std::endl;

	i->makeSound(); //will output the cat sound!
	j->makeSound();
	meta->makeSound();

	const WrongAnimal* wrongMeta = new WrongAnimal();
	const WrongAnimal* wrongKet = new WrongCat();

	std::cout << wrongKet->getType() << " " << std::endl;
	wrongKet->makeSound();
	wrongMeta->makeSound();

	delete(meta);
	delete(j);
	delete(i);
	delete(wrongMeta);
	delete(wrongKet); // Leak here!

	return 0;
}


#include "Brain.hpp"

Brain::Brain() {
	std::cout << "Brain constructor has been called!" << std::endl;
}

Brain::Brain(const Brain &other) {
	std::cout << "Brain copy constructor has been called!" << std::endl;
	std::copy(std::begin(other.ideas), std::end(other.ideas), std::begin(ideas));
}

Brain::~Brain() {
	std::cout << "Brain destructor has been called!" << std::endl;
}

Brain& Brain::operator=(const Brain& other) {
	std::cout << "Brain assignation operator called!" << std::endl;
	if (this != &other)
		std::copy(std::begin(other.ideas), std::end(other.ideas), std::begin(ideas));
	return *this;
}

void Brain::setFirstIdea(const std::string firstIdea) {
	ideas[0] = firstIdea;
}

std::string Brain::getFirstIdea() const {
	if (ideas[0] != "")
		return ideas[0];
	else
		return "nothing in there yet...";
}
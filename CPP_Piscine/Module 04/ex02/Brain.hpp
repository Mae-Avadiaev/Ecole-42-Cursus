#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include <string>

class Brain {

public:

	Brain();
	Brain(const Brain &other);
	~Brain();
	Brain& operator=(const Brain& other);

	void setFirstIdea(const std::string firstIdea);
	std::string getFirstIdea() const;

private:

	std::string ideas[100];

};

#endif
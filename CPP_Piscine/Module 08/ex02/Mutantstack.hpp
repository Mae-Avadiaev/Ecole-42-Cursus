#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>
#include <iterator>
#include <deque>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T> {

public:

	class iterator : public std::deque<T>::iterator {};

    MutantStack() : std::stack<T>() {}

    MutantStack(const MutantStack &other) : std::stack<T>(other) {}

    ~MutantStack() {};

    MutantStack& operator=(const MutantStack &other) {
		this->c = other.c;
		return *this;
	}

	iterator begin() {
		typename std::deque<T>::iterator temp = this->c.begin();
		return *(static_cast<iterator *>(&temp));
	}

	iterator end() {
		typename std::deque<T>::iterator temp = this->c.end();
		return *(static_cast<iterator *>(&temp));
	}

private:

    

};

#endif
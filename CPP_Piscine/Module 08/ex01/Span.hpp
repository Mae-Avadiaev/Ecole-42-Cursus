#ifndef SPAN_HPP
#define SPAN_HPP 

#include <exception>
#include <vector>
#include <iterator>

class Span {

	class FullVectorException : public std::exception {

		const char* what() const throw();

	};

	class NoSpanException : public std::exception {

		const char* what() const throw();

	};

	class NoEnoughSpace : public std::exception {

		const char* what() const throw();

	};

public:

    Span();
	Span(unsigned int n);
    Span(const Span &other);
    ~Span();
    Span& operator=(const Span &other);

	void addNumber(int num);
	void addRange(int* begin, int* end);
	int shortestSpan();
	int longestSpan();

private:

	std::vector<int> *arr;
	unsigned int size;
	unsigned int stored;
};

#endif
#include "Span.hpp"
#include <iostream>

Span::Span() {
	arr = new std::vector<int>;
	size = 0;
	stored = 0;
}

Span::Span(unsigned int n) {
	arr = new std::vector<int>;
	size = n;
	stored = 0;
}

Span::Span(const Span &other) {
	arr = new std::vector<int>;
	size = other.size;
	std::copy(other.arr->begin(), other.arr->end(), arr->begin());
	stored = other.stored;
}

Span::~Span() {
	delete arr;
}

Span& Span::operator=(const Span &other) {
    if (this != &other) {
		delete arr;
		arr = new std::vector<int>;
		size = other.size;
		std::copy(other.arr->begin(), other.arr->end(), arr->begin());
		stored = other.stored;
	}
    return *this;
}

void Span::addNumber(int num) {
	if (stored != size) {
		arr->push_back(num);
		stored++;
	} else {
		throw FullVectorException();
	}
}

void Span::addRange(int* begin, int* end) {
	if ((end - begin) + stored > size)
		throw NoEnoughSpace();
	arr->insert(arr->begin() + stored, begin, end);
	stored += (end - begin);
}

int Span::shortestSpan() {
	if (stored != 0 && stored != 1) {
		std::sort(arr->begin(), arr->end());
		int res = 0;
		int minSpan = INT_MAX;
		for (int i = stored - 1; i > 0; i--) {
			res = arr->at(i) - arr->at(i - 1);
			if (res < minSpan)
				minSpan = res;
		}
		return minSpan;
	} else {
		throw NoSpanException();
	}
}

int Span::longestSpan() {
	if (stored != 0 && stored != 1) {
		return *(std::max_element(arr->begin(), arr->end())) - *(std::min_element(arr->begin(), arr->end()));
	} else {
		throw NoSpanException();
	}
}

const char* Span::FullVectorException::what() const throw() {
	return "The array is full! You can't add more numbers!";
}

const char* Span::NoSpanException::what() const throw() {
	return "There is not enough elements to calculate the span!";
}

const char* Span::NoEnoughSpace::what() const throw() {
	return "The range is too big! There is no enough space in the array!";
}
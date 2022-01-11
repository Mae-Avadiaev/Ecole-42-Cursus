#include "Span.hpp"
#include <iostream>

int main() {

	Span sp = Span(5);
	Span noElements = Span();
	Span oneElement = Span(1);

	oneElement.addNumber(1);

	try {
		sp.addNumber(5);
		sp.addNumber(3);
		sp.addNumber(17);
		sp.addNumber(9);
		sp.addNumber(11);
		sp.addNumber(100);
	} catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}
	std::cout << "sp shortest span = " << sp.shortestSpan() << std::endl;
	std::cout << "sp longest span = " << sp.longestSpan() << std::endl;

	try {
		noElements.shortestSpan();
	} catch (std::exception& exception) {
		std::cout << "noElements shortest span = " << exception.what() << std::endl;
	}

	try {
		noElements.longestSpan();
	} catch (std::exception& exception) {
		std::cout << "noElements longest span = " << exception.what() << std::endl;
	}

	try {
		oneElement.shortestSpan();
	} catch (std::exception& exception) {
		std::cout << "oneElement shortest span = " << exception.what() << std::endl;
	}

	try {
		oneElement.longestSpan();
	} catch (std::exception& exception) {
		std::cout << "oneElement longest span = " << exception.what() << std::endl;
	}

	int testLen1 = 100;
	int tempArr[testLen1];
	for (int i = 0; i < testLen1; i++) {
		tempArr[i] = i;
	}

	Span testSpan1 = Span(testLen1);
	testSpan1.addNumber(400);

	try {
		testSpan1.addRange(tempArr, tempArr + testLen1);
	} catch (std::exception& exception) {
		std::cout << exception.what() << std::endl;
	}

	testSpan1.addRange(tempArr, tempArr + testLen1 - 1);

	std::cout	<< "The shortest span of testSpan1 is " << testSpan1.shortestSpan()
				<< std::endl;
	std::cout	<< "The longest span of testSpan1 is " << testSpan1.longestSpan()
				<< std::endl;


	int testLen2 = 20000;
	int tempArr2[testLen2];
	for (int i = 0; i < testLen2; i++) {
		tempArr2[i] = i;
	}

	Span testSpan2 = Span(testLen2 + 1);

	testSpan2.addNumber(-1);
	testSpan2.addRange(tempArr2, tempArr2 + testLen2);

	std::cout	<< "The shortest span of testSpan2 is " << testSpan2.shortestSpan()
				 << std::endl;
	std::cout	<< "The longest span of testSpan2 is " << testSpan2.longestSpan()
				 << std::endl;

	return 0;
}
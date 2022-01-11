#include "Mutantstack.hpp"

#include <iostream>
#include <list>

int main()
{
	std::cout << "----------Main with MutantStack----------" << std::endl;

	MutantStack<int> mstack;
	mstack.push(5);
	mstack.push(17);
	std::cout << mstack.top() << std::endl;
	mstack.pop();
	std::cout << mstack.size() << std::endl;
	mstack.push(3);
	mstack.push(5);
	mstack.push(737);
//[...]
	mstack.push(0);
	MutantStack<int>::iterator it = mstack.begin();
	MutantStack<int>::iterator ite = mstack.end();
	++it;
	--it;
	while (it != ite)
	{
		std::cout << *it << std::endl;
		++it;
	}
	std::stack<int> s(mstack);

	std::cout << "----------Main with std::list----------" << std::endl;

	std::list<int> testList;
	testList.push_back(5);
	testList.push_back(17);
	std::cout << testList.back() << std::endl;
	testList.pop_back();
	std::cout << testList.size() << std::endl;
	testList.push_back(3);
	testList.push_back(5);
	testList.push_back(737);
//[...]
	testList.push_back(0);
	std::list<int>::iterator itList = testList.begin();
	std::list<int>::iterator iteList = testList.end();
	++itList;
	--itList;
	while (itList != iteList)
	{
		std::cout << *itList << std::endl;
		++itList;
	}

	std::cout << "----------Other tests----------" << std::endl;

	MutantStack<int> first;
	MutantStack<int> second;

	first.push(1);
	second = first;
	second.pop();

	std::cout	<< "The size of first is " << first.size() << std::endl;
	std::cout	<< "And the size of second is " << second.size() << std::endl;

	return 0;
}
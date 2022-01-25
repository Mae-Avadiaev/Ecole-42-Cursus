#include <iostream>
#include <deque>
#include <stack>
#include "Stack.hpp"

int main () {
	std::stack<int> sTLStack;
	ft::stack<int> ftStack;

	//----------1. push()----------
	sTLStack.push(5);
	sTLStack.push(4);
	sTLStack.push(3);

	ftStack.push(5);
	ftStack.push(4);
	ftStack.push(3);


	//----------2. const push()----------
	const int a = 10;
	sTLStack.push(a);
	ftStack.push(a);

	std::cout << "-----------3. size()----------" << std::endl;
	std::cout << "STL: The size of the stack: " << sTLStack.size() << std::endl;
	std::cout << "Ft: The size of the stack: " << ftStack.size() << std::endl;

	std::cout << "-----------4. empty()----------" << std::endl;
	std::cout << "STL: Is empty: " << sTLStack.empty() << std::endl;
	std::cout << "Ft: Is empty: " << ftStack.empty() << std::endl;

	std::cout << "-----------5. top()----------" << std::endl;
	std::cout << "STL: On the top: " << sTLStack.top() << std::endl;
	std::cout << "Ft: On the top: " << ftStack.top() << std::endl;

	std::cout << "-----------6. pop()----------" << std::endl;
	std::cout << "STL: Popping element: " << sTLStack.top() << std::endl;
	std::cout << "STL: Size of stack: " << sTLStack.size() << std::endl;
	sTLStack.pop();
	std::cout << "STL: Previous  element: " << sTLStack.top() << std::endl;
	std::cout << "STL: Size of stack: " << sTLStack.size() << std::endl;
	std::cout << std::endl;
	std::cout << "Ft: Popping element: " << ftStack.top() << std::endl;
	std::cout << "Ft: Size of stack: " << ftStack.size() << std::endl;
	ftStack.pop();
	std::cout << "Ft: Previous element: " << ftStack.top() << std::endl;
	std::cout << "Ft: Size of stack: " << ftStack.size() << std::endl;

	std::cout << "-----------7. operator=()----------" << std::endl;
	std::stack<int> sTLStack2;
	std::cout << "STL: Is empty before =: " << sTLStack2.empty() << std::endl;
	sTLStack2 = sTLStack;
	std::cout << "STL: Is empty after =: " << sTLStack2.empty() << std::endl;
	std::cout << std::endl;
	ft::stack<int> ftStack2;
	std::cout << "Ft: Is empty before =: " << ftStack2.empty() << std::endl;
	ftStack2 = ftStack;
	std::cout << "Ft: Is empty after =: " << ftStack2.empty() << std::endl;

	std::cout << "-----------8. copyConstructor()----------" << std::endl;
	std::stack<int> sTLStack3(sTLStack);
	std::cout << "STL: STL1 top: " << sTLStack.top() << std::endl;
	std::cout << "STL: STL3 top: " << sTLStack3.top() << std::endl;
	std::cout << std::endl;
	ft::stack<int> ftStack3(ftStack);
	std::cout << "Ft: Ft1 top: " << ftStack.top() << std::endl;
	std::cout << "Ft: Ft3 top: " << ftStack3.top() << std::endl;

	return 0;
}


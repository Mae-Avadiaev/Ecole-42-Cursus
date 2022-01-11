#ifndef STACK_HPP
#define STACK_HPP 

namespace ft {

	class Stack {

	public:

		Stack();
		Stack(const Stack &other);
		~Stack();
		Stack& operator=(const Stack &other);

	private:
		_container;


	};
}

#endif
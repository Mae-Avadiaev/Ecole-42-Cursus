#ifndef STACK_HPP
#define STACK_HPP

namespace ft {
	// Template parameters
	template < class T, class Container = std::deque<T> > class stack {

	public:
		// Member types
		typedef Container container_type;
		typedef T value_type;
		typedef typename Container::size_type size_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;

		// Member functions
		explicit stack(const Container& cont = Container()) : _container(cont) {}

		stack(const stack& other) : _container(other._container) {}

		~stack() {}

		stack& operator=(const stack& other) {
			this->_container = other._container;
			return *this;
		}

		// Element access
		reference top() {
			return _container.back();
		}

		const_reference top() const {
			return _container.back();
		}

		// Capacity
		bool empty() const {
			return _container.empty();
		}

		size_type size() const {
			return _container.size();
		}

		// Modifiers
		void push(const value_type& value) {
			_container.push_back(value);
		}

		void pop() {
			_container.pop_back();
		}

	protected:

		Container _container;

	};

	template<class T, class Container>
	bool operator==(const stack<T,Container>& lhs, const std::stack<T,Container>& rhs) {
		return lhs._container == rhs._container;
	}

	template<class T, class Container>
	bool operator!=(const stack<T,Container>& lhs, const std::stack<T,Container>& rhs) {
		return lhs._container != rhs._container;
	}

	template<class T, class Container>
	bool operator<(const stack<T,Container>& lhs, const std::stack<T,Container>& rhs) {
		return lhs._container < rhs._container;
	}

	template<class T, class Container>
	bool operator<=(const stack<T,Container>& lhs, const std::stack<T,Container>& rhs) {
		return lhs._container <= rhs._container;
	}

	template<class T, class Container>
	bool operator>(const stack<T,Container>& lhs, const std::stack<T,Container>& rhs) {
		return lhs._container > rhs._container;
	}

	template<class T, class Container>
	bool operator>=(const stack<T,Container>& lhs, const std::stack<T,Container>& rhs) {
		return lhs._container >= rhs._container;
	}
}

#endif
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template<typename T>
class Container {

public:

	Container() {
		_arr = new T[0];
		_size = 0;
	}

	Container(int len) : {
		_arr = new T[len];
		_size = len;
	}

	~Container() {
		delete _arr;
	}

	Container(const Container& other) : _size(other._size) {
		std::copy(begin(other._arr), end(other._arr), begin(_arr));
	}

	Container& operator=(const Container& other) {
		delete _arr;
		_arr = new T[other._size];
		std::copy(begin(other._arr), end(other._arr), begin(_arr));
		_size = other._size;
	}

	T& operator[](const int) {

	}

	int size() {
		return _size;
	}

private:

	T* _arr;
	unsigned int _size;
};

template<typename ctr>
int* easyfind(ctr container, int targ) const {
	for (int i = 0; i < container.size(); i++)
		if (container[i] == targ)
			return &container[i];
	return NULL;
}

#endif
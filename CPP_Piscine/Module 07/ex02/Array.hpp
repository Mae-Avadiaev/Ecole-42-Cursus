#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array {

public:

	class OutOfRangeException: public std::exception {

	public:

		const char* what() { return "Index out of range"; }
	};

	Array() {
		_arr = new T[0];
	}

	Array(unsigned int n) {
		_arr = new T[n];
	}

	Array(const Array& other) {
		_arr = new T[other.size()];
		std::copy(std::begin(other._arr), std::end(other._arr), std::begin(_arr));
	}

	~Array() {};

	Array& operator=(const Array& other) {
		std::copy(std::begin(other._arr), std::end(other._arr), std::begin(_arr));
	}

	T& operator[](int index) const {
		if (index < 0)
			throw OutOfRangeException::OutOfRangeException;
		else if (index > _arr.size())
			throw OutOfRangeException::OutOfRangeException;
		return _arr[index];
	}

	int size() const {
		return static_cast<int>(sizeof(*_arr)/sizeof(T));
	}

private:

	T* _arr;

};

#endif
#ifndef ARRAY_HPP
#define ARRAY_HPP

template<typename T>
class Array {

public:

	class OutOfRangeException: public std::exception {

	public:

		const char* what() const _NOEXCEPT { return "Index out of range"; }
	};

	Array() {
		_arr = new T[0];
		_size = 0;
	}

	Array(unsigned int n) {
		_arr = new T[n];
		_size = n;
	}

	Array(const Array& other) {
		_arr = new T[other.size()];
		_size = other.size();
		for (int i = 0; i < other.size(); i++)
			_arr[i] = other._arr[i];
	}

	~Array() {};

	Array& operator=(const Array& other) {
		delete _arr;
		_arr = new T[other.size()];
		_size = other.size();
		for (int i = 0; i < other.size(); i++)
			_arr[i] = other._arr[i];
	}

	T& operator[](int index) const {
		if (index < 0)
			throw OutOfRangeException();
		else if (index >= this->size()) {
			throw OutOfRangeException();
		}
		return _arr[index];
	}

	int size() const {
		return _size;
	}

private:

	T* _arr;
	int _size;
};

#endif
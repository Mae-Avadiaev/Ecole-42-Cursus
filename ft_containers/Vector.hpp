#ifndef VECTOR_HPP
#define VECTOR_HPP 

//The formula to EXTEND CAPACITY of a vector
//In this implementation it is extended by half each time
#define NEWCAPACITY(oldCap) (oldCap + oldCap / 2)

namespace ft {

	template<typename T>
	class Vector {

	public:

		Vector() :
			_size(0), _capacity(2) {
			_array = new T[2];
		}

		Vector(const Vector& other) {
			*this = other;
		}

		Vector(Vector&& other) {
			*this = std::move(other);
		}

		~Vector() {
			clear(); //in case if T is data structure with heap allocated parameter(s)
			delete(_array, _capacity * sizeof(T)); //instead of "delete [] _array", because clear call all the destructors
		}

		Vector& operator=(const Vector& other) {
			if (this != &other) {
				_size = other._size;
				_capacity = other._capacity;
				delete[] _array;
				_array = new T[other._capacity];
				//copy
			}
			return *this;
		}

		Vector& operator=(Vector&& other) {
			if (this != &other) {
				delete [] _array;
				_size = other._size;
				_capacity = other._capacity;
				_array = std::move(other._array);

				other._size = 0;
				other._capacity = 0;
				other._array = nullptr;
			}
			return *this;
		}

		//----------F----------
		void push_back(const T& elem) {
			if (_capacity <= _size)
				reAlloc(_capacity + _capacity / 2);
			_array[_size] = elem;
			_size++;
		}

		void push_back(T&& elem) {
			if (_capacity <= _size)
				reAlloc(NEWCAPACITY(_capacity));
			_array[_size] = std::move(elem);
			_size++;
		}

		template<typename... Args>
		T& emplace_back(Args&&... args) {
			if (_size >= _capacity) {
				reAlloc(NEWCAPACITY(_capacity))
			}
			new(&_array[_size]) T(std::forward<args>(args)...);
			return _array[_size++];
		}

		void pop_back() {
			if (_size > 0)
				_array[_size--].~T();
		}

		void clear() {
			for (size_t i = 0; i < _size; i++)
				_array[i].~T();
			_size = 0;
		}

		T& operator[](size_t index) {
			if (index >= _size)
				//assert
			return _array[index];
		}

		const T& operator[](size_t index) const {
			if (index >= _size)
				//assert
			return _array[index];
		}

		T& at(int) {

		}

		size_t size() const {
			return _size;
		}

		void swap() {

		}

	private:

		T* _array;
		size_t _capacity;
		size_t _size;

		void reAlloc(size_t newCapacity) {
			if (newCapacity < _size) //case of shrinking
				_size = newCapacity;

			T* newBlock = (T*)new(newCapacity * sizeof(T));

			for (size_t i = 0; i < _size; i++)
				newBlock[i] = std::move(_array[i]);

			for (size_t i = 0; i < _size; i++)
				_array[i].~T();

			delete(_array, _capacity * sizeof(T));
			_array = newBlock;
			_capacity = newCapacity;
		}

	};
}

#endif
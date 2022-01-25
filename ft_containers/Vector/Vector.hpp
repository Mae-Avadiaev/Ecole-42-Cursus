#ifndef VECTOR_HPP
#define VECTOR_HPP 

//The formula to EXTEND CAPACITY of a vector
//In this implementation it is extended by half each time
#define NEWCAPACITY(oldCap) (oldCap + oldCap / 2)

/*
	The structure of the Vector.hpp
	Member types				|>	Aliases within vector class

 	Member functions			|>	Functions that have access to all the members
 									of the class.
 		I. Essential functions
			1. constructors		|> 	Construct a class instance
				A. default		|>  Constructs an empty container
				B. fill			|>	Constructs a container with n elements.
									each element is a copy of val.
				C. range		|>	Constructs a container with as many elements as
									the range [first,last], with each element
									constructed from its corresponding element
									in that range, in the same order.
				D. copy			|>	Constructs a container with a copy of each of
									the elements in x, in the same order.
			4. destructor		|>	This destroys all container elements, and
									deallocates all the storage capacity allocated
									by the vector using its allocator.
			5. operator=		|>	Copies all the elements from x into the container
									replacing its current contents, and modifying
									its size accordingly.
			6. assign			|>
				A. range
				B. fill
		II. Element access functions
			1. at
				A. default
				B. const
			2. operator[]
			3. front
			4. back
			5. data

		III. Capacity
			1. empty
			2. size
			3. max_size
			4. reserve
			5. capacity

		IV. Modifiers
			1. clear
			2. insert
			3. erase
			4. push_back
			5. pop_back
			6. resize
			7. swap

		V. Allocator
			1. get_allocator

	Non-member functions
 			1. operator==	|
			2. operator!=	|
			3. operator<	|
			4. operator<=	|>	lexicographically compares the values in the vector
			5. operator>	|
			6. operator>=	|



*/





namespace ft {

	template< typename T, class Allocator = std::alocator<T> > class vector {

	public:

		// Member types
		typedef T value_type;
		typedef Allocator allocator_type;
		typedef std::size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef value_type& reference;
		typedef const value_type& const_reference;
		typedef typename Allocator::pointer pointer;
		typedef typename Allocator::const_pointer const_pointer;
		typedef RandomAccessIterator<value_type> iterator;
		typedef RandomAccessIterator<const value_type> const_iterator;
		typedef reverse_iterator<iterator> reverse_iterator;
		typedef reverse_iterator<const_iterator> const_reverse_iterator;

		// Member functions	|>	I. Essential functions	|> 1. Constructors |> A. Default
		explicit vector (const allocator_type& alloc = allocator_type()) {

		}

		// Member functions	|>	I. Essential functions	|>	1. constructors	|>	B. fill
		explicit vector (
				size_type n,
				const value_type& val = value_type(),
				const allocator_type& alloc = allocator_type()) {

		}

		// Member functions	|>	I. Essential functions	|>	1. constructors	|>	C. range
		template <class InputIterator>
		vector (
			InputIterator first,
			InputIterator last,
			const allocator_type& alloc = allocator_type()) {

		}

		// Member functions	|>	I. Essential functions	|>	1. constructors	|>	D. copy
		vector (const vector& x) {

		}

		// Member functions	|>	I. Essential functions	|>	4. destructor
		~vector() {}

		// Member functions	|>	I. Essential functions	|>	5. operator=
		vector& operator= (const vector& x) {

		}

		// Member functions	|>	I. Essential functions	|>	6. assign	|>	A. range
		template <class InputIterator>
		void assign (InputIterator first, InputIterator last) {

		}

		// Member functions	|>	I. Essential functions	|>	6. assign	|>	B. fill
		void assign (size_type n, const value_type& val) {

		}

		// Member functions	|>	II. Element access functions |>	1. at	|>	A. Default
		reference at (size_type n) {

		}

		// Member functions	|>	II. Element access functions |>	1. at	|>	B. Const
		const_reference at (size_type n) const {

		}

		// Member functions	|>	II. Element access functions |>	2. operator[]	|>	A. Default
		reference operator[] (size_type n) {

		}

		// Member functions	|>	II. Element access functions |>	3. operator[]	|>	B. Const
		const_reference operator[] (size_type n) const {

		}

		// Member functions	|>	II. Element access functions |>	3. front	|>	A. Default

		// Member functions	|>	II. Element access functions |>	3. front	|>	B. Const

		// Member functions	|>	II. Element access functions |>	4. back	|>	A. Default
		reference back() {

		}

		// Member functions	|>	II. Element access functions |>	4. back	|>	B. Const
		const_reference back() const {

		}

		// Member functions	|>	II. Element access functions |>	5. data


		// Member functions	|>	III. Capacity |>	1. empty
		// Member functions	|>	III. Capacity |>	2. size
		// Member functions	|>	III. Capacity |>	3. max_size
		// Member functions	|>	III. Capacity |>	4. reserve
		// Member functions	|>	III. Capacity |>	5. capacity


		// Member functions	|>	IV. Modifiers	|>	1. clear
		// Member functions	|>	IV. Modifiers	|>	2. insert
		// Member functions	|>	IV. Modifiers	|>	3. erase
		// Member functions	|>	IV. Modifiers	|>	4. push_back
		// Member functions	|>	IV. Modifiers	|>	5. pop_back
		// Member functions	|>	IV. Modifiers	|>	6. resize
		// Member functions	|>	IV. Modifiers	|>	7. swap


		// Member functions	|>	V. Allocator	|>	1. get_allocator

		// Non-member functions	|>	1. operator==
		// Non-member functions	|>	2. operator!=
		// Non-member functions	|>	3. operator<
		// Non-member functions	|>	4. operator<=
		// Non-member functions	|>	5. operator>
		// Non-member functions	|>	6. operator>=




















		vector(const Vector& other) {
			*this = other;
		}

		vector(Vector&& other) {
			*this = std::move(other);
		}

		~vector() {
			clear(); //in case if T is data structure with heap allocated parameter(s)
			delete(_array, _capacity * sizeof(T)); //instead of "delete [] _array", because clear call all the destructors
		}

		vector& operator=(const Vector& other) {
			if (this != &other) {
				_size = other._size;
				_capacity = other._capacity;
				delete[] _array;
				_array = new T[other._capacity];
				//copy
			}
			return *this;
		}

		vector& operator=(Vector&& other) {
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
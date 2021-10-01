#ifndef BASE_A_B_C_HPP
#define BASE_A_B_C_HPP

class Base {

public:

	virtual ~Base() {}

};

class A: public Base {
	~A() {}
};

class B: public Base {
	~B() {}
};

class C: public Base {
	~C() {}
};

#endif
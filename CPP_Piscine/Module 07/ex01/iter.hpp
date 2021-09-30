#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>

template<typename T>
void addFive(T& i) {
	i += 5;
}

template<typename R, typename T>
void iter(R* adr, int len, T* func) {
	for (int i = 0; i < len; i++)
		func(adr[i]);
}

#endif
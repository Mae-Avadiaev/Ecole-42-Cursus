#ifndef EASYFIND_HPP
#define EASYFIND_HPP

template<typename T>
int* easyfind(T& arr, int targ) const {
	int lenArr = sizeof(arr)/sizeof(arr[0]);
	for (int i = 0; i < lenArr; i++)
		if (arr[i] == targ)
			return arr + i;
	return NULL;
}

#endif
#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <iostream>
#include <algorithm>

template<typename ctr>
typename ctr::const_iterator easyfind(const ctr& container, int targ) {
	return std::find(container.begin(), container.end(), targ);
}

#endif
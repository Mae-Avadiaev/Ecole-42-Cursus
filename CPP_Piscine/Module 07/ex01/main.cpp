#include "iter.hpp"
#include <string>

int main() {

	int intArr[3] = {1, 2, 3};
	int lenI = static_cast<int>(sizeof(intArr)/sizeof(intArr[0]));
	iter(intArr, lenI, addFive);
	for(int i = 0; i < lenI; i++)
		std::cout << intArr[i];
	std::cout << std::endl;

	char string[] = "abcdef";
	int lenS = static_cast<int>(sizeof(string)/sizeof(string[0]));
	iter(string, lenS, addFive);
	std::cout << string << std::endl;

	return 0;

}

//class Awesome {
//public:
//	Awesome(void) :_n(42) {return;}
//	int get(void) const {return this->_n;}
//private:
//	int _n;
//};
//std::ostream& operator<< (std::ostream& o, Awesome const & rsh) {o << rsh.get(); return o;}
//template<typename T>
//void print(T& x) {std::cout << x << std::endl; return;}
//int main() {
//	int tab[] = {0,1,2,3,4};
//	Awesome tab2[5];
//
//	iter(tab, 5, print);
//	iter(tab2, 5, print);
//
//	return 0;
//}
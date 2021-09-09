#include "Fixed.hpp"
#include <iostream>

int main( void ) {
	std::cout << "----------Arithmetic operations----------" << std::endl;
	Fixed const b( Fixed( 5.05f ) * Fixed( 2 ) );
	std::cout << "Multiplication: " << b << std::endl;
	Fixed const c(Fixed(5.10f) / Fixed(2));
	std::cout << "Division: " << c << std::endl;
	Fixed const d(Fixed(2.123456f) + Fixed(2.123456f));
	std::cout << "Addition: " << d << std::endl;
	Fixed const e(Fixed(2.123456f) - Fixed(4.123456f));
	std::cout << "Subtraction: " << e << std::endl;

	std::cout << "----------Comparison operators----------" << std::endl;
	std::cout << "Operator >: " << b << " > " << c << " = " << (b > c) << std::endl;
	std::cout << "Operator <: " << b << " < " << c << " = " << (b < c) << std::endl;
	std::cout << "Operator >=: " << b << " >= " << c << " = " << (b >= c) << std::endl;
	std::cout << "Operator <=: " << b << " <= " << c << " = " << (b <= c) << std::endl;
	std::cout << "Operator ==: " << b << " == " << c << " = " << (b == c) << std::endl;
	std::cout << "Operator !=: " << b << " != " << c << " = " << (b != c) << std::endl;

	std::cout << "----------Incs & decs----------" << std::endl;
	Fixed a;
	std::cout << "Default value: " << a << std::endl;
	std::cout << "Pre-increment: " << ++a << std::endl;
	std::cout << "Value: " << a << std::endl;
	std::cout << "Post-increment: " << a++ << std::endl;
	std::cout << "Value: " << a << std::endl;
	std::cout << "Pre-decrement: " << --a << std::endl;
	std::cout << "Value: " << a << std::endl;
	std::cout << "Post-decrement: " << a-- << std::endl;
	std::cout << "Value: " << a << std::endl;
	std::cout << a << " max " << b << " = " << Fixed::max( a, b ) << std::endl;
	std::cout << a << " min " << b << " = " << Fixed::min( a, b ) << std::endl;
	return 0;
}
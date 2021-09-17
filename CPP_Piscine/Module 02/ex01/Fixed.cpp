#include "Fixed.hpp"
#include <iostream>

Fixed::Fixed() : _value(0) {
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const int val) {
	std::cout << "Int constructor called" << std::endl;
	setRawBits(val << _fBits);
}

Fixed::Fixed(const float val) {
	std::cout << "Float constructor called" << std::endl;
	setRawBits((val * (float)(1 << _fBits)));
}

Fixed::~Fixed() {
	std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(const Fixed& other) {
	std::cout << "Copy constructor called" << std::endl;
	_value = other._value;
}

Fixed& Fixed::operator=(const Fixed &other) {
	std::cout << "Assignation operator called" << std::endl;
	_value = other._value;
	return *this;
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}

int Fixed::getRawBits(void) const {
	std::cout << "getRawBits member function called" << std::endl;
	return this->_value;
}

void Fixed::setRawBits(const int raw) {
	this->_value = raw;
}

float Fixed::toFloat(void) const {
	return ((float)_value / (float)(1 << _fBits));
}

int Fixed::toInt(void) const {
	return (_value >> _fBits);
}
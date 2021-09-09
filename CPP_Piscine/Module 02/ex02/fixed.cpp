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

//----------Assignation operator overload----------

Fixed& Fixed::operator=(const Fixed& other) {
	std::cout << "Assignation operator called" << std::endl;
	_value = other._value;
	return *this;
}

//----------Comparison operators overloads----------

bool Fixed::operator>(const Fixed& other) const {
	return _value > other._value ? 1 : 0;
}

bool Fixed::operator<(const Fixed& other) const {
	return _value < other._value ? 1 : 0;
}

bool Fixed::operator>=(const Fixed& other) const {
	return _value >= other._value ? 1 : 0;
}

bool Fixed::operator<=(const Fixed& other) const {
	return _value <= other._value ? 1 : 0;
}

bool Fixed::operator==(const Fixed& other) const {
	return _value == other._value ? 1 : 0;
}

bool Fixed::operator!=(const Fixed& other) const {
	return _value != other._value ? 1 : 0;

}

//----------Arithmetic operators overloads----------

Fixed& Fixed::operator+(const Fixed& other) {
	_value += other._value;
	return *this;
}

Fixed& Fixed::operator-(const Fixed& other) {
	_value -= other._value;
	return *this;
}

Fixed& Fixed::operator*(const Fixed& other) {
	_value = ((std::int64_t)_value * (std::int64_t)other._value) >> _fBits;
	return *this;
}

Fixed& Fixed::operator/(const Fixed& other) {
	_value = ((int64_t)_value << _fBits) / (int64_t)other._value;
	return *this;
}

//----------Incs & Decs operators overloads----------

Fixed& Fixed::operator++(void) {
	_value += 1;
	return *this;
}

Fixed Fixed::operator++(int) {
	Fixed temp = *this;
	++*this;
	return temp;
}

Fixed& Fixed::operator--(void) {
	_value -= 1;
	return *this;
}

Fixed Fixed::operator--(int) {
	Fixed temp = *this;
	--*this;
	return temp;
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

Fixed& Fixed::min(Fixed& a, Fixed& b) {
	return a < b ? a : b;
}

Fixed& Fixed::max(Fixed& a, Fixed& b) {
	return a > b ? a : b;
}

const Fixed& Fixed::min(const Fixed& a, const Fixed& b) {
	return a < b ? a : b;
}

const Fixed& Fixed::max(const Fixed& a, const Fixed& b) {
	return a > b ? a : b;
}

std::ostream& operator<<(std::ostream& out, const Fixed &fixed) {
	out << fixed.toFloat();
	return out;
}
#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cstdint>
class Fixed {

public:

	Fixed();
	Fixed(const int val);
	Fixed(const float val);
	~Fixed();
	Fixed(const Fixed& other);
	int getRawBits(void) const;
	void setRawBits(int const raw);
	float toFloat(void) const;
	int toInt(void) const;

	Fixed& operator=(const Fixed &other);

	bool operator<(const Fixed &other) const;
	bool operator>(const Fixed &other) const;
	bool operator<=(const Fixed &other) const;
	bool operator>=(const Fixed &other) const;
	bool operator==(const Fixed &other) const;
	bool operator!=(const Fixed &other) const;

	Fixed& operator+(const Fixed& other);
	Fixed& operator-(const Fixed& other);
	Fixed& operator*(const Fixed& other);
	Fixed& operator/(const Fixed& other);

	Fixed& operator++(void);
	Fixed operator++(int);
	Fixed& operator--(void);
	Fixed operator--(int);

	static Fixed& min(Fixed& a, Fixed& b);
	static Fixed& max(Fixed& a, Fixed& b);

	static const Fixed& min(const Fixed& a, const Fixed& b);
	static const Fixed& max(const Fixed& a, const Fixed& b);

private:

	int					_value;
	static const int	_fBits = 8;

};

std::ostream& operator<<(std::ostream& out, const Fixed &fixed);

#endif
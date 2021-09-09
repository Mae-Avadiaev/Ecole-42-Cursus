#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
class Fixed {

public:

	Fixed();
	~Fixed();
	Fixed(const Fixed& other);
	Fixed& operator=(const Fixed &other);
	int getRawBits(void) const;
	void setRawBits(int const raw);

private:

	int					_value;
	static const int	_fBits = 8;

};

#endif
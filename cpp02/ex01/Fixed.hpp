#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed
{
private:
	int rawBits;
	const static int fractionalBits = 8;

public:
	Fixed();
	Fixed(const Fixed &fixed);
	~Fixed();
	Fixed &operator=(const Fixed &fixed);
	int getRawBits(void) const;
	void setRawBits(int const raw);

	Fixed(const int nb);
	Fixed(const float nbFloat);
	float toFloat( void ) const;
	int toInt( void ) const;
};

std::ostream &operator<<(std::ostream &o, Fixed const &i);

#endif
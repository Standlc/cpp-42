#include "Fixed.hpp"

Fixed::Fixed()
{
	std::cout << "Default constructor called\n";
	rawBits = 0;
}

Fixed::Fixed(const Fixed &fixed)
{
	std::cout << "Copy constructor called\n";
	operator=(fixed);
}

Fixed::Fixed(const int nb)
{
	std::cout << "Int constructor called\n";
	rawBits = nb << fractionalBits;
}

Fixed::Fixed(const float nbFloat)
{
	std::cout << "Float constructor called\n";
	rawBits = std::roundf(nbFloat * (1 << fractionalBits));
}

Fixed::~Fixed()
{
	std::cout << "Destructor called" << std::endl;
}

Fixed &Fixed::operator=(const Fixed &fixed)
{
	std::cout << "Copy assignment operator called" << std::endl;
	rawBits = fixed.getRawBits();
	return *this;
}

// METHODS

int Fixed::getRawBits(void) const
{
	return rawBits;
}

void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (float)rawBits / (1 << fractionalBits);
}

int Fixed::toInt(void) const
{
	return rawBits >> fractionalBits;
}

std::ostream &operator<<(std::ostream &output, Fixed const &fixed)
{
	output << fixed.toFloat();
	return output;
}
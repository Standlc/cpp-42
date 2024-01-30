#include "Fixed.hpp"

Fixed::Fixed()
{
	rawBits = 0;
}

Fixed::Fixed(const Fixed &a)
{
	*this = a;
}

Fixed::Fixed(const int nb)
{
	rawBits = nb << fractionalBits;
}

Fixed::Fixed(const float nbFloat)
{
	rawBits = roundf(nbFloat * (1 << fractionalBits));
}

Fixed::~Fixed()
{
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

// OPERATORS OVERLOAD

std::ostream &operator<<(std::ostream &output, Fixed const &a)
{
	output << a.toFloat();
	return output;
}

Fixed &Fixed::operator=(const Fixed &a)
{
	rawBits = a.getRawBits();
	return *this;
}

Fixed Fixed::operator/(const Fixed &a)
{
	return Fixed(this->toFloat() / a.toFloat());
}

Fixed Fixed::operator-(const Fixed &a)
{
	return Fixed(this->toFloat() - a.toFloat());
}

Fixed Fixed::operator*(const Fixed &a)
{
	return Fixed(this->toFloat() * a.toFloat());
}

Fixed Fixed::operator+(const Fixed &a)
{
	return Fixed(this->toFloat() + a.toFloat());
}

bool Fixed::operator>(const Fixed &a)
{
	return rawBits > a.getRawBits();
}

bool Fixed::operator>=(const Fixed &a)
{
	return rawBits >= a.getRawBits();
}

bool Fixed::operator<(const Fixed &a)
{
	return rawBits < a.getRawBits();
}

bool Fixed::operator<=(const Fixed &a)
{
	return rawBits <= a.getRawBits();
}

bool Fixed::operator!=(const Fixed &a)
{
	return rawBits != a.getRawBits();
}

bool Fixed::operator==(const Fixed &a)
{
	return rawBits == a.getRawBits();
}

Fixed &Fixed::operator++()
{
	rawBits++;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed prevValueFixed(*this);
	rawBits++;
	return prevValueFixed;
}

Fixed &Fixed::operator--()
{
	rawBits--;
	return *this;
}

Fixed Fixed::operator--(int)
{
	Fixed prevValueFixed(*this);
	rawBits--;
	return prevValueFixed;
}

// MIN / MAX

Fixed &Fixed::max(Fixed &a, Fixed &b)
{
	if (a > b)
		return a;
	return b;
}

const Fixed &Fixed::max(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() > b.getRawBits())
		return a;
	return b;
}

Fixed &Fixed::min(Fixed &a, Fixed &b)
{
	if (a < b)
		return a;
	return b;
}

const Fixed &Fixed::min(const Fixed &a, const Fixed &b)
{
	if (a.getRawBits() < b.getRawBits())
		return a;
	return b;
}

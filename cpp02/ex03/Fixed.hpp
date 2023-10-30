#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>
#include <cmath>

class Fixed {
	int rawBits;
	const static int fractionalBits = 8;

	public:
		Fixed();
		Fixed(const Fixed &fixed);
		Fixed(const int nb);
		Fixed(const float nbFloat);
		~Fixed();

		int getRawBits() const;
		void setRawBits(int const raw);
		float toFloat() const;
		int toInt() const;

		Fixed &operator=(const Fixed &fixed);
		Fixed operator/(const Fixed &fixed);
		Fixed operator-(const Fixed &fixed);
		Fixed operator*(const Fixed &fixed);
		Fixed operator+(const Fixed &fixed);

		bool operator>(const Fixed &fixed);
		bool operator>=(const Fixed &fixed);
		bool operator<(const Fixed &fixed);
		bool operator<=(const Fixed &fixed);
		bool operator!=(const Fixed &fixed);
		bool operator==(const Fixed &fixed);

		Fixed &operator++();
		Fixed operator++(int);
		Fixed &operator--();
		Fixed operator--(int);

		static Fixed &max(Fixed &a, Fixed &b);
		const static Fixed &max(const Fixed &a, const Fixed &b);
		static Fixed &min(Fixed &a, Fixed &b);
		const static Fixed &min(const Fixed &a, const Fixed &b);
};

std::ostream &operator<<(std::ostream &output, Fixed const &a);

#endif
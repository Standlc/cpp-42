#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point {
	const Fixed x;
	const Fixed y;
	public:
		Point();
		Point(const float x, const float y);
		Point(const Point &point);
		~Point();
		Point &operator=(const Point &point);

		Fixed getX() const;
		Fixed getY() const;
};

#endif
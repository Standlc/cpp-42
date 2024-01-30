#include "Point.hpp"

Point::Point() : x(0), y(0)
{
}

Point::Point(const float x1, const float y1) : x(x1), y(y1)
{
}

Point::Point(const Point &point)
{
	*this = point;
}

Point::~Point()
{
}

Point &Point::operator=(const Point &point)
{
	(Fixed &)x = point.getX();
	(Fixed &)y = point.getY();
	return *this;
}

Fixed Point::getX() const
{
	return x;
}

Fixed Point::getY() const
{
	return y;
}

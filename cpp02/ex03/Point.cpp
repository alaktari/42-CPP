#include "Point.hpp"

Point::Point(void) : x(0), y(0)
{
	/* default constructor */
}

Point::Point(const float x, const float y) : x(x), y(y)
{
	/* Parameterized constructor */
}

Point::Point(const Point& other) : x(other.x), y(other.y)
{
	/* Copy constructor */
}

Point::~Point(void)
{
	/* Destructor */
}

Point &Point::operator=(const Point &other)
{
	/* copy assignment operator */
	if (this == &other)
		return *this;
	return *this;
}

const Fixed& Point::get_coordinates(int which) const
{
	if (which == 1)
		return x;
	else
		return y;
}

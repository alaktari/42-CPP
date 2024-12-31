#include "Point.hpp"

const float _epsilon = 1.0f / (1 << Fixed::getFractionalBits());

static float area(Point const& a, Point const& b, Point const& c)
{
	Fixed a_x(a.get_coordinates(1)), a_y(a.get_coordinates(2)), 
	b_x(b.get_coordinates(1)), b_y(b.get_coordinates(2)),
	c_x(c.get_coordinates(1)), c_y(c.get_coordinates(2));

	return std::abs(a_x * (b_y - c_y) + b_x * (c_y - a_y) + c_x * (a_y - b_y)) / 2;
}

bool bsp( Point const a, Point const b, Point const c, Point const point)
{
	float total_area = area(a, b, c);
	
	float area1 = area(a, b, point);
	float area2 = area(a, c, point);
	float area3 = area(b, c, point);

	// Check if p is a vertex by comparing it with each of a, b, and c
	if (((a.get_coordinates(1).toFloat() == point.get_coordinates(1).toFloat()) &&
		(a.get_coordinates(2).toFloat() == point.get_coordinates(2).toFloat())) ||
		(((b.get_coordinates(1).toFloat() == point.get_coordinates(1).toFloat()) &&
		(b.get_coordinates(2).toFloat() == point.get_coordinates(2).toFloat()))) ||
		(((c.get_coordinates(1).toFloat() == point.get_coordinates(1).toFloat()) &&
		(c.get_coordinates(2).toFloat() == point.get_coordinates(2).toFloat()))))
	{
		// std::cout << "The point is a vertex of the triangle.\n";
		return false;
	} // Point is a vertex of the triangle

	// Check if point p is on any of the edges
	if (std::abs(area1) <= _epsilon || std::abs(area2) <= _epsilon || std::abs(area3) <= _epsilon)
	{
		// std::cout << "The point is on the edge of the triangle.\n";
		return false;  // Point is on the edge of the triangle
	}

	// Check if the sum of the areas equals the total area (point is inside)
	if (std::abs(total_area - (area1 + area2 + area3)) <= _epsilon)
		return true;  // Point is inside the triangle
	
	return false;  // Point is outside the triangle
}


#include <iostream>
#include "Fixed.hpp"
#include "Point.hpp"

int main()
{
	Point a(5, 2);
	Point b(3, 5);
	Point c(1, 2);

	Point p(3, 2);

	if (bsp(a, b, c, p))
		std::cout << "The point is inside the triangle.\n";
	else
		std::cout << "The point is outside the triangle.\n";
}

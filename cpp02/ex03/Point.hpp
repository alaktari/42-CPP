#ifndef POINT_HPP
#define POINT_HPP

#include "Fixed.hpp"

class Point
{
    private:
        const Fixed x;
        const Fixed y;
        static const float _epsilon;
    public:
        Point(void);
        Point(const float x, const float y);
        Point(const Point& other);
        Point &operator=(const Point& other);
        ~Point(void);
        const Fixed& get_coordinates(int which) const;
};

bool bsp( Point const a, Point const b, Point const c, Point const point);

#endif
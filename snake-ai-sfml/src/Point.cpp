#include "Point.h"

Point::Point() : x(-1), y(-1) {}
Point::Point(int x, int y) : x(x), y(y) {}


void Point::set(int x, int y)
{
	this->x = x;
	this->y = y;
	return;
}

bool Point::operator==(const Point& p)
{
	return ( this->x == p.x && this->y == p.y );
}

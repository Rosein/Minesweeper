
#include "../include/Point.hpp"


namespace Minesweeper
{

	bool Point::operator ==(const Point& other) const 
	{
		return (this->x == other.x) && (this->y == other.y);
	}

	bool Point::operator !=(const Point& other) const 
	{
		return !(*this == other);
	}
}
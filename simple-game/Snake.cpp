#include "Snake.h"

Snake::Snake( Map* m) : map(m)
{
	body.push_back(Point{ 0, 0 });
}

Snake::Snake( Map* m, Point starting_position, Direction d) :
	map(m), d(d)
{
	body.push_back( Point{ starting_position } );
}

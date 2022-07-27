#pragma once
#include <vector>
#include "Map.h"
#include "Utilities.h"

using std::vector;

enum class Direction { Up, Right, Left, Down };

class Snake
{
	public:
		 Snake( Map* m);
		 Snake( Map* m, Point starting_position, Direction d);

	private:
		Map* map;

		Direction d{ Direction::Up };
		vector<Point> body;
};


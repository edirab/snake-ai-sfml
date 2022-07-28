#pragma once
#include <vector>
#include <list>
#include "Map.h"
#include "Utilities.h"

using std::vector;
using std::list;

enum class Direction { Up, Right, Left, Down };

class Snake
{
	public:
		Snake( Map* m);
		Snake( Map* m, Point starting_position, Direction d);

		void draw(sf::RenderWindow* window);

		void move();
		Direction d{ Direction::Up };

	private:
		Map* map;


		/*
			vector represents a snake's body in reversed order.
			It's head is at body.size() - 1
		*/
		list<Point> body;
		bool is_alive{true};

		sf::Color body_color = sf::Color::Magenta;
};

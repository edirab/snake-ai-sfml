#pragma once

#include <vector>
#include <list>
//#include "Snake.h"
#include "Point.h"
#include "Map.h"
#include "Utilities.h"
#include <iostream>

using std::vector;
using std::list;
using std::cout;

enum class Direction { Up, Right, Left, Down };

class Map;

class Snake
{
	public:
		//Snake() = delete;
		explicit Snake( Map* m);
		explicit Snake( Map* m, Point starting_position, Direction d);

		void draw(sf::RenderWindow* window);
		
		void move();

		bool isAlive();
		int get_length();

		void set_position( const Point& pos );
		void set_diraction( const Direction& dir);
		void reset();

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

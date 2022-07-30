#pragma once

#include <vector>
#include <list>
#include "Utilities.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Food.h"
#include "Point.h"
#include "RamdomPoint.h"
#include "Map.h"
#include "Utilities.h"
#include <iostream>

using std::vector;
using std::list;
using std::cout;

enum class Direction { Up, Right, Left, Down };

class Snake
{
	public:
		//Snake() = delete;
		//Snake();
		explicit Snake(MapParams params, Food& f, Point starting_position, Direction d);
		//explicit Snake(Food& f, Point starting_position, Direction d);

		void init_map( Map* m);

		void draw(sf::RenderWindow* window);
		
		void move();

		bool isAlive();
		int get_length();

		void set_position( const Point& pos );
		void set_diraction( const Direction& dir);
		void reset();

		Direction d{ Direction::Up };

	private:
		MapParams params;
		Food& food;
		

		/*
			vector represents a snake's body in reversed order.
			It's head is at body.size() - 1
		*/
		list<Point> body;
		bool is_alive{true};

		sf::Color body_color = sf::Color::Magenta;
};

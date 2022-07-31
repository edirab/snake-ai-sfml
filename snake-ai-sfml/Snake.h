#pragma once

#include <vector>
#include <list>
#include "Utilities.h"
#include <iostream>

#include <SFML/Graphics.hpp>
#include "Food.h"
#include "Point.h"
#include "RamdomPoint.h"
#include "Utilities.h"
#include <iostream>
#include <math.h>

using std::vector;
using std::list;
using std::cout;
using std::abs;
using std::min;

enum class Direction { Up, Right, Left, Down };

class Snake
{
	public:
		explicit Snake(MapParams params, Food& f, Point starting_position, Direction d);

		void draw(sf::RenderWindow* window);
		
		/*!
		* \brief moves snake one block in a set direction,
		* checks for food and collisions
		*/
		void move();

		bool isAlive();
		int get_length() const;
		const list<Point>* get_body() const;

		void set_position( const Point& pos );
		void set_direction( const Direction& dir);
		Direction get_direction() const;

		void reset();

		void get_ai_inputs(vector<int>& inputs);

	private:
		MapParams params;
		Food& food;
		Direction d{ Direction::Up };
		

		/*!
			\brief
			list represents a snake's body. Easy to add to head and remove
			from tail
		*/
		list<Point> body;

		bool is_alive{true};

		sf::Color body_color = sf::Color::Magenta;

		void collision(Point& head_new);
};

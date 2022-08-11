#pragma once

#include <vector>
#include <list>
#include "Utilities.h"
#include <iostream>

#include <SFML/Graphics.hpp>

#include "GameWindow.h"
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
using std::sqrt;

enum class Direction { Up, Right, Left, Down };

class Snake
{
	public:

		/*!
		* \brief Minimal c-tor
		* \details Does nothing only initializes Food& ref. Call randomize() explicitly
		*/
		Snake(Food& f);

		/*!
		* \brief Snake with specified position and length. Direction is Up
		*/
		explicit Snake(Food& f, Point starting_position, int length);

		explicit Snake(Food& f, Point starting_position, Direction d);

		void draw();
		
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

		/*!
		* \brief resets snake's position to the center. Clears body
		*/
		void reset();

		/*!
		* \brief clears body, randomizes starting position and food position
		*/
		void randomize(bool true_random = false);

		/*!
		* \brief provides inputs for neural network
		* \details snake provides 26 params in total:
		* 3 groups of 8 rays (dist to walls, food and body) + 
		* current direction and body length
		*/
		void get_ai_inputs(vector<float>& inputs);

	private:
		sf::RenderWindow* window{nullptr};

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

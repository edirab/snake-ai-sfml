#pragma once
#include "RamdomPoint.h"
#include "MapParams.h"
#include "GameWindow.h"

#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

using std::cout;
using std::list;

class Food
{
public:
	/*!
	* \brief Default c-tor
	* \details sets position to 1, 0 cos right no in c-tor impossible 
	* to determine snake's body. spawn() should be called after
	*/
	Food( bool true_random = true );
	explicit Food(int x, int y);

	/*!
	* \brief Calculates new food location taking into consideration snake's body
	*/
	void spawn(const list<Point>* );
	void draw();

	bool eaten = true;

	Point position;
	sf::Color color = sf::Color::Green;

private:
	sf::RenderWindow* window{nullptr};
	MapParams params;
	RandomPoint rp;
};

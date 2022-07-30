#pragma once
#include "RamdomPoint.h"
#include "MapParams.h"
#include <SFML/Graphics.hpp>
#include <list>
#include <iostream>

using std::cout;
using std::list;

class Food
{
public:
	Food();
	explicit Food(sf::RenderWindow* window, MapParams params, int x, int y);
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


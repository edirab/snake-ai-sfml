#pragma once
#include "Point.h"
#include <SFML/Graphics.hpp>

class Food
{
public:
	Food();

	bool eaten = true;

	Point position;
	sf::Color color = sf::Color::Green;
private:
	

};


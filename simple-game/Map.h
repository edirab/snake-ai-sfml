#pragma once
#include <SFML/Graphics.hpp>
//#include "Snake.h"
#include "Food.h"

class Map
{
public:
	Map(const sf::RenderWindow* window);
	Map(const sf::RenderWindow* window, int w, int h);

	//Snake s;
	Food f;

	void spawn_food();

	void draw_map()
	{

	}

private:
	const sf::RenderWindow* window{ nullptr };

	const int width{ 20 };
	const int heihgt{ 20 };

	const int n_of_food{ 1 };

	sf::Color background_color{sf::Color::Black};
	sf::Color grid_color{sf::Color::White};
};


#pragma once
#include <SFML/Graphics.hpp>
//#include "Snake.h"
#include "Food.h"
#include "Utilities.h"

class Map
{
public:
	Map(sf::RenderWindow* window);
	Map(sf::RenderWindow* window, int w, int h);

	//Snake s;
	Food f;
	RandomPoint rp;

	void spawn_food();

	void draw_map();

	void draw_grid();

private:
	sf::RenderWindow* window{ nullptr };

	float cell_size{ 40 }; // cell size in pixels
	const int width{ 20 }; // map size in cells
	const int heihgt{ 20 };

	const int n_of_food{ 1 };

	sf::Color background_color{sf::Color::Black};
	sf::Color grid_color{sf::Color::White};
};


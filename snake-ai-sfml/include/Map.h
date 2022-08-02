#pragma once
#include "Utilities.h"
#include <iostream>
#include "MapParams.h"
#include <SFML/Graphics.hpp>

using std::cout;

class Map
{
public:
	explicit Map(sf::RenderWindow* window, MapParams params);

	/*!
	* \brief Draws grid
	*/
	void draw();

private:
	sf::RenderWindow* window{ nullptr };

	MapParams params;
	const int n_of_food{ 1 };

	sf::Color background_color{sf::Color::Black};
	sf::Color grid_color{sf::Color::White};

	void draw_grid();
};


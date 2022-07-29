#pragma once
#include <SFML/Graphics.hpp>
//#include "Snake.h"
#include "Food.h"
#include "Point.h"
#include "RamdomPoint.h"
#include "Utilities.h"

class Map
{
public:
	explicit Map(sf::RenderWindow* window);
	explicit Map(sf::RenderWindow* window, int w, int h);

	//Snake s;
	Food f;
	RandomPoint rp;

	/*!
	* \brief Draws grid (if enabled), spams and draws food
	*/
	void draw_map();

	int get_width();
	int get_height();
	int get_cell_size();
	//Point get_food_pos() { return f.position; }

	void reset();

private:
	sf::RenderWindow* window{ nullptr };

	float cell_size{ 40 }; // cell size in pixels
	const int width{ 20 }; // map size in cells
	const int height{ 20 };
	const int n_of_food{ 1 };

	sf::Color background_color{sf::Color::Black};
	sf::Color grid_color{sf::Color::White};

	void spawn_food();

	void draw_grid();
};


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

	int get_width() { return width; }
	int get_height() { return height; }
	int get_cell_size() { return cell_size; }
	Point get_food_pos() { return f.position; }

private:
	sf::RenderWindow* window{ nullptr };

	float cell_size{ 40 }; // cell size in pixels
	const int width{ 20 }; // map size in cells
	const int height{ 20 };

	const int n_of_food{ 1 };

	sf::Color background_color{sf::Color::Black};
	sf::Color grid_color{sf::Color::White};
};


#pragma once
#include <vector>
#include <list>
#include "Utilities.h"
#include <iostream>
#include "Food.h"
#include "Point.h"
#include "RamdomPoint.h"
#include "MapParams.h"
#include <SFML/Graphics.hpp>

using std::cout;




class Map
{
public:
	//explicit Map(sf::RenderWindow* window);
	explicit Map(sf::RenderWindow* window, MapParams params);
	//explicit Map(sf::RenderWindow* window, Snake* s, int w, int h);

	//Snake* s{nullptr};
	//	Food f;
	RandomPoint rp;

	/*!
	* \brief Draws grid (if enabled), spams and draws food
	*/
	void draw();

	//void init_snake(Snake* s);
	//Point get_food_pos() { return f.position; }

	void reset();

private:
	sf::RenderWindow* window{ nullptr };
	//Snake* s; //{nullptr};

	MapParams params;
	const int n_of_food{ 1 };

	sf::Color background_color{sf::Color::Black};
	sf::Color grid_color{sf::Color::White};



	void draw_grid();
};


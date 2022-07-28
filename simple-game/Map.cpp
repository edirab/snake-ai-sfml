#include "Map.h"

Map::Map(sf::RenderWindow* window) : window(window), rp(20, 20, false) {}

Map::Map(sf::RenderWindow* window, int w, int h) : width(w), heihgt(h), rp(h, w, true)
{
	
}

void Map::spawn_food()
{
	f.position = rp.generate();
}

void Map::draw_map()
{
	spawn_food();
	draw_grid();

	// draw food
	sf::RectangleShape food_shape( sf::Vector2f( cell_size, cell_size ) );
	food_shape.setPosition( sf::Vector2f( f.position.x * cell_size, f.position.y * cell_size ) );
	food_shape.setFillColor( f.color );

	window->draw(food_shape);
}

void Map::draw_grid()
{
	// draw horizontal lines
	for (int i = 0; i < heihgt + 1; i++)
	{
		float y_coord = i * cell_size;
		DrawLine(	0, 
					y_coord,
					cell_size * width, 
					y_coord,
					grid_color, this->window
				);
	}
	// draw vertical lines
	for (int i = 0; i < width + 1; i++)
	{
		float x_coord = i * cell_size;
		DrawLine
		(		x_coord,
				0,
				x_coord,
				cell_size * heihgt,
				grid_color, this->window
		);
	}
	return;
}

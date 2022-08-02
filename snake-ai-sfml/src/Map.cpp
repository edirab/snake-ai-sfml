#include "Map.h"

Map::Map(sf::RenderWindow* window, MapParams params) :
	window(window), params(params)
{ }

void Map::draw()
{
	draw_grid();
}

void Map::draw_grid()
{
	// draw horizontal lines
	for (int i = 0; i < params.height + 1; i++)
	{
		float y_coord = i * params.cell_size;
		DrawLine(	this->window,
					0, 
					y_coord,
					params.cell_size * params.width, 
					y_coord,
					grid_color
				);
	}
	// draw vertical lines
	for (int i = 0; i < params.width + 1; i++)
	{
		float x_coord = i * params.cell_size;
		DrawLine
		(		this->window,
				x_coord,
				0,
				x_coord,
				params.cell_size * params.height,
				grid_color
		);
	}
	return;
}

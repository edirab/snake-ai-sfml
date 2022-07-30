#include "Map.h"


//Map::Map(sf::RenderWindow* window) : window(window), rp(20, 20, false) {}
//
Map::Map(sf::RenderWindow* window, MapParams params) :
	window(window), params(params)
{
	
}

//Map::Map(sf::RenderWindow* window, Snake* s, int w, int h) : 
//	width(w), height(h), 
//	rp(h, w, true),
//	s(s)
//{
//	
//}

//void Map::init_snake(Snake* s) { this->s = s; return; }




void Map::draw()
{
	//spawn_food();
	draw_grid();
}


void Map::draw_grid()
{
	// draw horizontal lines
	for (int i = 0; i < params.height + 1; i++)
	{
		float y_coord = i * params.cell_size;
		DrawLine(	0, 
					y_coord,
					params.cell_size * params.width, 
					y_coord,
					grid_color, this->window
				);
	}
	// draw vertical lines
	for (int i = 0; i < params.width + 1; i++)
	{
		float x_coord = i * params.cell_size;
		DrawLine
		(		x_coord,
				0,
				x_coord,
				params.cell_size * params.height,
				grid_color, this->window
		);
	}
	return;
}


void Map::reset()
{
	//this->spawn_food();
}

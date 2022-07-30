#pragma once

#include "Food.h"

Food::Food() 
{
	position.x = 1;
	position.y = 0;
}

Food::Food(sf::RenderWindow* window, MapParams params, int x, int y) : 
		window(window),
		params(params),  
		rp(params.height, params.width, true)
{
	position.x = x;
	position.y = y;
}


void Food::spawn()
{
	if ( eaten == true )
	{
		position = rp.generate();
		eaten = false;
	}
	return;
}

void Food::draw()
{
	// draw food
	sf::RectangleShape food_shape( sf::Vector2f( params.cell_size, params.cell_size ) );
	food_shape.setPosition( sf::Vector2f( position.x * params.cell_size, position.y * params.cell_size ) );
	food_shape.setFillColor( color );

	this->window->draw(food_shape);
	return;
}
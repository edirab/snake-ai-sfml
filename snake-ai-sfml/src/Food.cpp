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
		rp(params.height, params.width, false)
{
	position.x = x;
	position.y = y;
}


void Food::spawn(const list<Point>* body)
{
	bool food_pos_valid = false;
	if ( eaten == true )
	{
		while(!food_pos_valid)
		{
			position = rp.generate();
			food_pos_valid = true;

			for (auto it = body->begin(); it != body->end(); ++it)
			{
				if ( it->x == position.x && it->y == position.y )
				{
					cout << "Invalid food pos\n";
					food_pos_valid = false;
				}
			}
		}
		eaten = false;
	}
	return;
}

void Food::draw()
{
	sf::RectangleShape food_shape( sf::Vector2f( params.cell_size, params.cell_size ) );
	food_shape.setPosition( sf::Vector2f( position.x * params.cell_size, position.y * params.cell_size ) );
	food_shape.setFillColor( color );

	this->window->draw(food_shape);
	return;
}
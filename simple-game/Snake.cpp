#include "Snake.h"
//#include "Map.h"

//Snake::Snake()
//{
//	body.push_back(Point{ 10, 10 });
//}

Snake::Snake(MapParams params, Food& f, Point starting_position, Direction d) :
	params(params), food(f), d(d)
{
	body.push_back( Point{ starting_position } );
}

//Snake::Snake(Food& f, Point starting_position, Direction d) :
//	food(f), d(d)
//{
//	body.push_back( Point{ starting_position } );
//}

void Snake::draw(sf::RenderWindow* window)
{
	int w = params.width;
	int h = params.height;
	int cell_size = params.cell_size;

	for (auto it = body.begin(); it != body.end(); it++)
	{
		DrawRectangle(window, 
			it->x * cell_size, 
			it->y * cell_size, 
			cell_size, 
			cell_size, 
			this->body_color);
	}
}

void Snake::move()
{
	Point head;

	if (this->d == Direction::Up)
	{
		head.set(body.begin()->x, body.begin()->y - 1);
		if (head.y < 0)
		{
			this->is_alive = false;
			return;
		}
		body.push_front(head);
	}
	else if (this->d == Direction::Right)
	{
		head.set(body.begin()->x + 1, body.begin()->y );
		if (head.x >= params.width)
		{
			this->is_alive = false;
			return;
		}
		body.push_front(head);
	}
	else if (this->d == Direction::Down)
	{
		head.set(body.begin()->x, body.begin()->y + 1);
		if (head.y >= params.height)
		{
			this->is_alive = false;
			return;
		}
		body.push_front(head);
	}
	else if (this->d == Direction::Left)
	{
		head.set(body.begin()->x - 1, body.begin()->y );
		if (head.x < 0)
		{
			this->is_alive = false;
			return;
		}
		body.push_front(head);
	}

	//
	if ( food.position == head)
	{
		cout << "Collect food\n";
		food.eaten = true;
	}
	else
	{
		body.pop_back();
	}
	return;
}


bool Snake::isAlive() 
{ 
	return this->is_alive; 
}

int Snake::get_length()
{
	return this->body.size();
}

void Snake::set_position( const Point& pos )
{
	this->body.clear();
	body.push_back( pos );
	return;
}


void Snake::set_diraction( const Direction& dir)
{
	this->d = dir;
	return;
}

void Snake::reset()
{
	is_alive = true;
	body.clear();
	body.push_back( Point( params.width/2, params.height / 2 ) );
	return;
}

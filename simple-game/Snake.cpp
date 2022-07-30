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
		sf::Color c;
		if (it == body.begin())
		{
			c = sf::Color::Yellow;
		}
		else
		{
			c = this->body_color;
		}

		DrawRectangle(window, 
			it->x * cell_size, 
			it->y * cell_size, 
			cell_size, 
			cell_size, 
			c);
	}
	return;
}

void Snake::move()
{
	Point head;

	if (this->d == Direction::Up)
	{
		head.set(body.begin()->x, body.begin()->y - 1);
	}
	else if (this->d == Direction::Right)
	{
		head.set(body.begin()->x + 1, body.begin()->y );
	}
	else if (this->d == Direction::Down)
	{
		head.set(body.begin()->x, body.begin()->y + 1);
	}
	else if (this->d == Direction::Left)
	{
		head.set(body.begin()->x - 1, body.begin()->y );
	}
	collision(head);

	//
	if (is_alive && food.position == head)
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

void Snake::collision(Point& head_new)
{
	if (head_new.y < 0 || head_new.y > params.height || head_new.x < 0 || head_new.x > params.width)
	{
		this->is_alive = false;
	}
	else
	{
		// chack for self collision
		for (auto it = body.begin(); it != body.end(); ++it)
		{
			if (*it == head_new)
			{
				this->is_alive = false;
				return;
			}
		}
		this->body.push_front(head_new);
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


void Snake::set_direction( const Direction& dir)
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

const list<Point>* Snake::get_body() const
{
	return (const list<Point>*) &body;
}
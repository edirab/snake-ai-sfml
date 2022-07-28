#include "Snake.h"

Snake::Snake( Map* m) : map(m)
{
	body.push_back(Point{ m->get_height()/2, m->get_width() / 2 });
}

Snake::Snake( Map* m, Point starting_position, Direction d) :
	map(m), d(d)
{
	body.push_back( Point{ starting_position } );
}

void Snake::draw(sf::RenderWindow* window)
{
	int w = map->get_width();
	int h = map->get_height();
	int cell_size = map->get_cell_size();

	//for (int i = 0; i < body.size(); i++)
	//{
	//	DrawRectangle(window, 
	//		body[i].x * cell_size, 
	//		body[i].y * cell_size, 
	//		cell_size, 
	//		cell_size, 
	//		this->body_color);
	//}
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
	if (this->d == Direction::Up)
	{
		Point head{body.begin()->x, body.begin()->y - 1};
		body.push_front(head);
		body.pop_back();

		for (int i = 0; i < body.size(); i++)
		{

		}
	}
	else if (this->d == Direction::Right)
	{
		Point head{body.begin()->x + 1, body.begin()->y };
		body.push_front(head);
		body.pop_back();
	}
	else if (this->d == Direction::Down)
	{
		Point head{body.begin()->x, body.begin()->y + 1};
		body.push_front(head);
		body.pop_back();
	}
	else if (this->d == Direction::Left)
	{
		Point head{body.begin()->x - 1, body.begin()->y };
		body.push_front(head);
		body.pop_back();
	}
	return;
}

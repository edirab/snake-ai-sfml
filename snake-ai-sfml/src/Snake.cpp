#include "Snake.h"

Snake::Snake(Food& f) : food(f) 
{
	window = GameWindow::get();
	randomize(true);
}

Snake::Snake(Food& f, Point starting_position, Direction d) :
	food(f), d(d)
{
	window = GameWindow::get();
	body.push_back( Point{ starting_position } );
}

void Snake::draw()
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
	
	// draw dotted line across body
	if (body.size() > 1)
	{
		sf::Color c = sf::Color::Blue;
		std::vector<sf::Vertex> vertices;
		auto it = body.begin();
		for (  ; it != --body.end();   )
		{
			vertices.push_back( sf::Vertex( 
					sf::Vector2f( 
						it->x * cell_size + cell_size / 2, 
						it->y * cell_size + cell_size / 2 ), 
					c )
			);
			++it;
		}
		window->draw( &vertices[0], vertices.size(), sf::Lines );
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
	if (is_alive)
	{
		if(food.position == head)
		{
			cout << "Collect food\n";
			food.eaten = true;
			food.spawn( this->get_body() );
			food.draw();
		}
		else
		{
			body.pop_back();
		}
	}
	return;
}

void Snake::collision(Point& head_new)
{
	if (head_new.y < 0 || head_new.y > params.height - 1 || head_new.x < 0 || head_new.x > params.width - 1)
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

int Snake::get_length() const
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

Direction Snake::get_direction() const
{
	return this->d;
}

void Snake::reset()
{
	is_alive = true;
	body.clear();
	body.push_back( Point( params.width/2, params.height / 2 ) );
	return;
}

void Snake::randomize(bool true_random)
{
	RandomPoint rp(params.height, params.width, !true_random);
	body.clear();
	body.push_back( rp.generate() );
	is_alive = true;

	// TODO: randomize direction 
	// (later, when we check that initially generated Eigen matrices are different)

	food.spawn(this->get_body());
	return;
}

const list<Point>* Snake::get_body() const
{
	return (const list<Point>*) &body;
}

void Snake::get_ai_inputs(vector<int>& inputs)
{
	inputs.clear();
	inputs.resize(26);

	Point head = *(body.begin());

	int dist_to_upper_wall = head.y;
	int dist_to_lower_wall = params.height - 1 - head.y; 
	int dist_to_right_wall = params.width - 1 - head.x;
	int dist_to_left_wall = head.x;

	/*
		thus snake cannot move diagonally floating point numbers
		representing hypotenuse will tell little to neural network.
		Let's calculate a chess distanse - amount of moves requiret to get to food.
		In case of a 45* rays it will simple become (2 * smallest triangle side)
	*/ 
	int dist_to_wall_upper_right = min<int>( dist_to_upper_wall, dist_to_right_wall ) * 2; // to upper right side
	int dist_to_wall_lower_right = min<int>( dist_to_lower_wall, dist_to_right_wall ) * 2; // lower right
	int dist_to_wall_lower_left = min<int>( dist_to_lower_wall, dist_to_left_wall ) * 2; // lower left
	int dist_to_wall_upper_left = min<int>( dist_to_upper_wall, dist_to_left_wall ) * 2; // upper left

	// find distances for food;
	int dist_to_food_upper = -1;
	int dist_to_food_lower = -1;
	int dist_to_food_right = -1;
	int dist_to_food_left = -1;

	// scan with upper and lower rays
	if (this->food.position.x == head.x)
	{
		dist_to_food_upper = abs( head.y - food.position.y );
	}
	// scan with right and left rays
	if (this->food.position.y == head.y)
	{
		dist_to_food_left = abs( head.x - food.position.x );
	}

	int dist_to_food_upper_right = -1;
	int dist_to_food_lower_right = -1;
	int dist_to_food_lower_left = -1;
	int dist_to_food_upper_left = -1;

	Point normalized_food_pos = this->food.position;
	normalized_food_pos.x -= head.x;
	normalized_food_pos.y -= head.y; // now head is center of new coord system

	// this means that foor item lies on diagonal either y = x or y = -x
	if ( abs(normalized_food_pos.x) == abs(normalized_food_pos.y) )
	{
		// now we need to determin a sector
		if (normalized_food_pos.x > 0 && normalized_food_pos.y < 0 )
		{
			dist_to_food_upper_right = abs(2 * normalized_food_pos.x);
		} 
		else if ( normalized_food_pos.x > 0 && normalized_food_pos.y > 0 )
		{
			dist_to_food_lower_right = abs(2 * normalized_food_pos.x);
		}
		else if ( normalized_food_pos.x < 0 && normalized_food_pos.y > 0 )
		{
			dist_to_food_lower_left = abs(2 * normalized_food_pos.x);
		}
		else if ( normalized_food_pos.x < 0 && normalized_food_pos.y < 0 )
		{
			dist_to_food_upper_left = abs(2 * normalized_food_pos.x);
		}
	}

	// distance to snake itself
	int min_dist_to_snake_upper = -1;
	int min_dist_to_snake_right = -1;
	int min_dist_to_snake_lower = -1;
	int min_dist_to_snake_left = -1;

	// distance to snake itself diagonally
	int min_dist_to_snake_upper_right = -1;
	int min_dist_to_snake_lower_right = -1;
	int min_dist_to_snake_lower_left = -1;
	int min_dist_to_snake_upper_left = -1;

	/*
		Traverse snake's body and count which rays it's crossing
	*/
	for (auto it = body.begin(); it != body.end(); ++it)
	{
		// strinctly less, or otherwise head == head
		if (it->x == head.x && it->y < head.y)
		{
			int dist = head.y - it->y;
			if ( min_dist_to_snake_upper == -1 )
			{
				min_dist_to_snake_upper == dist;
			}
			else
			{
				min_dist_to_snake_upper = min( min_dist_to_snake_upper, dist );
			}
		}
		// right
		if (it->y == head.y && it->x > head.x)
		{
			int dist = it->x - head.x;
			if ( min_dist_to_snake_right == -1 )
			{
				min_dist_to_snake_right == dist;
			}
			else
			{
				min_dist_to_snake_right = min( min_dist_to_snake_right, dist );
			}
		}
		// down
		if (it->x == head.x && it->y > head.y)
		{
			int dist =  it->y - head.y;
			if ( min_dist_to_snake_lower == -1 )
			{
				min_dist_to_snake_lower == dist;
			}
			else
			{
				min_dist_to_snake_lower = min( min_dist_to_snake_lower, dist );
			}
		}
		// left
		if (it->y == head.y && it->x < head.x)
		{
			int dist = head.x - it->x;
			if ( min_dist_to_snake_left == -1 )
			{
				min_dist_to_snake_left == dist;
			}
			else
			{
				min_dist_to_snake_left = min( min_dist_to_snake_left, dist );
			}
		}
		// TODO: all diagonals

		Point normalized_body_item_pos = *it;
		normalized_body_item_pos.x -= head.x;
		normalized_body_item_pos.y -= head.y;

		if ( normalized_body_item_pos.x == normalized_body_item_pos.y )
		{
			// upper_right
			if (normalized_body_item_pos.x > 0 && normalized_body_item_pos.y < 0)
			{
				if (min_dist_to_snake_upper_right == -1)
				{
					min_dist_to_snake_upper_right = 2 * abs(normalized_body_item_pos.x);
				}
				else
				{
					min_dist_to_snake_upper_right = min( min_dist_to_snake_upper_right, 2 * normalized_body_item_pos.x ) ;
				}
			}
			// lower_right
			else if (normalized_body_item_pos.x > 0 && normalized_body_item_pos.y > 0)
			{
				if (min_dist_to_snake_lower_right == -1)
				{
					min_dist_to_snake_lower_right = 2 * abs(normalized_body_item_pos.x);
				}
				else
				{
					min_dist_to_snake_lower_right = min( min_dist_to_snake_lower_right, 2 * normalized_body_item_pos.x ) ;
				}
			}
			// lower left
			else if (normalized_body_item_pos.x < 0 && normalized_body_item_pos.y > 0)
			{
				if (min_dist_to_snake_lower_left == -1)
				{
					min_dist_to_snake_lower_left = 2 * abs(normalized_body_item_pos.x);
				}
				else
				{
					min_dist_to_snake_lower_left = min( min_dist_to_snake_lower_left, 2 * normalized_body_item_pos.x ) ;
				}
			}
			// upper left 
			else if (normalized_body_item_pos.x < 0 && normalized_body_item_pos.y < 0)
			{
				if (min_dist_to_snake_upper_left == -1)
				{
					min_dist_to_snake_upper_left = 2 * abs(normalized_body_item_pos.x);
				}
				else
				{
					min_dist_to_snake_upper_left = min( min_dist_to_snake_upper_left, 2 * normalized_body_item_pos.x ) ;
				}
			}
		}
	} // end traversing snake 

	int direction = 0;

	if (this->d == Direction::Up)
	{
		direction = 1;
	}
	else if (this->d == Direction::Right)
	{
		direction= 2;
	}
	else if (this->d == Direction::Down)
	{
		direction = 3;
	}
	else if (this->d == Direction::Down)
	{
		direction = 4;
	}

	inputs[0] = dist_to_upper_wall;
	inputs[1] = dist_to_right_wall;
	inputs[2] = dist_to_lower_wall;
	inputs[3] = dist_to_left_wall;

	inputs[4] = dist_to_wall_upper_right;
	inputs[5] = dist_to_wall_lower_right;
	inputs[6] = dist_to_wall_lower_left;
	inputs[7] = dist_to_wall_upper_left;

	inputs[8] = dist_to_food_upper; 
	inputs[9] = dist_to_food_right;
	inputs[10] = dist_to_food_lower;
	inputs[11] = dist_to_food_left;
	
	inputs[12] = dist_to_food_upper_right;
	inputs[13] = dist_to_food_lower_right;
	inputs[14] = dist_to_food_lower_left;
	inputs[15] = dist_to_food_upper_left;

	inputs[16] = min_dist_to_snake_upper;
	inputs[17] = min_dist_to_snake_right;
	inputs[18] = min_dist_to_snake_lower;
	inputs[19] = min_dist_to_snake_left;

	inputs[20] = min_dist_to_snake_upper_right;
	inputs[21] = min_dist_to_snake_lower_right;
	inputs[22] = min_dist_to_snake_lower_left;
	inputs[23] = min_dist_to_snake_upper_left;

	inputs[24] = direction;
	inputs[25] = this->body.size();

	return;
}

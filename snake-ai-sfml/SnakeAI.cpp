#include "SnakeAI.h"

SnakeAI::SnakeAI(
	sf::RenderWindow* window, 
	Food f, Point startint_position, Direction d) : 
		window(window), 
		food(window, 10, 10),
		snake(window, f, startint_position, d)
{ }

SnakeAI::SnakeAI(
	sf::RenderWindow* window,
	Food &f, Point& startint_position, Direction d,
	NeuralNet& net) 
	: window(window), snake(window, f, startint_position, d),
	  brain(net)
{ }


//void SnakeAI::play()
//{
//	while (snake.isAlive() && n_moves_left)
//	{
//		food.spawn(snake.get_body());
//		this->make_decision();
//		snake.move();
//
//		n_moves_left--;
//	}
//	return;
//}

float SnakeAI::fitness()
{
	calc_fitness();
	return this->m_fitness;
}

void SnakeAI::calc_fitness()
{
	this->m_fitness = (snake.get_length() - 1) * 1000;
	this->m_fitness += (600 - n_moves_left);
}

void SnakeAI::draw()
{
	food.draw();
	snake.draw();
}

void SnakeAI::play()
{
	//Map map{window, params};

	sf::Clock* clock = new sf::Clock();
	clock->restart();

	float moves_per_second{4};
	float period_ms = 1 / moves_per_second * 1000 ;


	while (window->isOpen())
    {
        //processEvents(snake);
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

        if (clock->getElapsedTime().asMilliseconds() > period_ms)
        {
            //cout << "Total frames: " << total_frames << " " << clock->getElapsedTime().asMilliseconds() << "\n";
            clock->restart();
            window->clear();

            if (snake.isAlive() && n_moves_left)
            {
				food.spawn( snake.get_body() );
				this->make_decision();
				snake.move();

                //map.draw();
                food.draw();
                snake.draw();
                window->display();    
                //total_frames++;
                
                //update_score(snake.get_length() - 1);
                //snake.get_ai_inputs(inputs);
                //print_ai_inputs(inputs);

				n_moves_left--;
            }
            else
            {
                // reset game
                //snake.reset();
                //window->setTitle("Score: 0");
            }
        }
    }
	 window->close();
	 return;
}

void SnakeAI::make_decision()
{
	int index = 0;

	snake.get_ai_inputs(this->inputs);

	auto res =  brain.pass(inputs);
	auto it_max = max_element(res.begin(), res.end());

	if (it_max != res.end())
	{
		double max_val = *it_max;
		auto it_index = find(res.begin(), res.end(), max_val);

		index = distance(res.begin(), it_index);
	}

	switch(index)
	{
	case 0:
		snake.set_direction( Direction::Up );
		break;
	case 1:
		snake.set_direction( Direction::Right );
		break;
	case 2:
		snake.set_direction( Direction::Down );
		break;
	case 3:
		snake.set_direction( Direction::Left );
		break;
	}

	return;
}
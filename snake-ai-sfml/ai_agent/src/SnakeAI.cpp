#include "SnakeAI.h"

SnakeAI::SnakeAI( EvolutionParams& p )
	: 
		window(GameWindow::get()),
		params(p),
		brain(p),
		snake(food, Point(10, 10), 3 )
{
	window->setFramerateLimit(60);
}

SnakeAI::SnakeAI( EvolutionParams& p, NeuralNet& net )
	:
		window(GameWindow::get()),
		params(p),
		brain(p, net),
		snake(food, Point(10, 10), 3)
{
	window->setFramerateLimit(60);
}

SnakeAI::SnakeAI( EvolutionParams& p,
	Food f, Point startint_position, Direction d) 
	: 
		window(GameWindow::get()), 
		params(p),
		brain(p),
		food(10, 10),
		snake(f, startint_position, d)
{
	window->setFramerateLimit(60);
}

SnakeAI::SnakeAI( EvolutionParams& p,
	Food &f, Point& startint_position, Direction d,
	NeuralNet& net) 
	: 
		window(GameWindow::get()),
		params(p),
		brain(p, net),
		snake(f, startint_position, d)
{
	window->setFramerateLimit(60);
}

float SnakeAI::get_fitness()
{
	calc_fitness();
	return this->m_fitness;
}

SnakeAI* SnakeAI::breed(const SnakeAI* parent)
{
	NeuralNet child = this->brain.crossover(parent->brain);
	SnakeAI* child_ai = new SnakeAI{params, child};
	return child_ai;
}

void SnakeAI::calc_fitness()
{
	if (snake.get_length() - 1 < 10)
	{
		this->m_fitness = m_lifetime * m_lifetime * powf(2, snake.get_length() - 1);
	}
	else
	{
		this->m_fitness = m_lifetime * m_lifetime * powf(2, 10) *  (snake.get_length() - 1);
	}
	//this->m_fitness = (snake.get_length() - 1) * 1000;
	//this->m_fitness += (N_MOVES_ALLOWED - n_moves_left);
	return;
}

void SnakeAI::draw()
{
	food.draw();
	snake.draw();
	return;
}

void SnakeAI::step()
{
	if (snake.isAlive() && m_lifetime < params.lifetime)
    {
		food.spawn( snake.get_body() );
		this->make_decision();
		snake.move();

		if (m_draw)
		{
			//map.draw();
			food.draw();
			snake.draw();
		}
		m_lifetime++;
    }
	return;
}

void SnakeAI::play()
{
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
            clock->restart();
            window->clear();

            if (snake.isAlive() && m_lifetime < params.lifetime)
            {
				food.spawn( snake.get_body() );
				this->make_decision();
				snake.move();

                //map.draw();
                food.draw();
                snake.draw();
                window->display();    
                
				m_lifetime++;
            }
            else
            {
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

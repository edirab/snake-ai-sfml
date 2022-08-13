#include "Population.h"


Population::Population(EvolutionParams& p)
	: params(p)
{
	for (int i = 0; i < p.species_in_generation; ++i)
	{
		SnakeAI* agent = new SnakeAI(p);
		agents.push_back(agent);
	}
}

Population::Population(vector<SnakeAI*> new_generation, EvolutionParams& p)
	: params(p)
{
	this->agents = new_generation;
}

Population::~Population()
{
	for (auto elem : agents)
	{
		delete elem;
	}
}

void Population::simulate()
{
	sf::Clock* clock = new sf::Clock();
	clock->restart();

	float period_ms = 1 / float(params.moves_per_sec) * 1000 ;

	sf::RenderWindow* window = GameWindow::get();
	while (window->isOpen() && this->someone_still_alive())
    {
		sf::Event event;
		while (window->pollEvent(event) && this->someone_still_alive())
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

        if (clock->getElapsedTime().asMilliseconds() > period_ms)
        {
            clock->restart();
            window->clear();

			for (int i = 0; i < agents.size(); ++i)
			{
				agents[i]->step();
			}
			window->display();
		}
	}
	return;
}

vector<SnakeAI*>Population::breed()
{
	vector<SnakeAI*> new_generation;
	vector<SnakeAI*> n_best_agents = select.truncation(this->params, this->agents);
	cout << "Best fitness: " << select.get_best_fitness() << "\n";

	/*
		Preserfe best from previous genaration.
		Maybe we'll display it later
	*/
	new_generation.push_back( n_best_agents[0]->clone() );
	/*
	* mate agents randomly
	*/
	random_device rd;
	mt19937 generator(rd());
	uniform_int_distribution<> distr(0, params.species_in_generation - 1);

	SnakeAI* new_agent;
	int counter = params.species_in_generation - 1;

	int first = 0;
	int second = 0;

	while( counter )
	{
		first = distr(generator);
		second = distr(generator); // TODO: potential bug here

		new_agent = agents[ first ]->breed( agents[ second ] );
		new_generation.push_back(new_agent);

		counter--;
	}
	return new_generation;
}

float Population::get_best_fitness()
{
	return m_best_fitness;
}

bool Population::someone_still_alive()
{
	bool one_is_alive = false;
	for (auto agent : agents)
	{
		if (agent->snake.isAlive() && agent->get_lifetime() < params.lifetime)
		{
			one_is_alive = true;
		}
	}
	return one_is_alive;
}

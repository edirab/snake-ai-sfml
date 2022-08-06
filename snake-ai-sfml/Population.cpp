#include "Population.h"

Population::Population(int n_species) 
	: number_of_species(n_species)
{
	//agents.resize(number_of_species);
	for (int i = 0; i < number_of_species; ++i)
	{
		SnakeAI* agent = new SnakeAI();
		agents.push_back(agent);
	}
}

void Population::simulate()
{
	sf::Clock* clock = new sf::Clock();
	clock->restart();

	float moves_per_second{4};
	float period_ms = 1 / moves_per_second * 1000 ;

	sf::RenderWindow* window = GameWindow::get();
	while (window->isOpen())
    {
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

			for (int i = 0; i < agents.size(); ++i)
			{
				agents[i]->step();
			}
			window->display();
		}
	}
	return;
}

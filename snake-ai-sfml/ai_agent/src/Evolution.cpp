#include "Evolution.h"

Evolution::Evolution( EvolutionParams& p )
	:
	params(p)
{
}

void Evolution::start()
{
	sf::RenderWindow* window = GameWindow::get();
	Population* population = nullptr;
	vector<SnakeAI*> next_gen;

	int generation_counter = 0;

	while (window->isOpen() && generation_counter < params.num_generations)
	{
		cout << "\tGeneration: " << generation_counter << " ";
		if (population == nullptr)
		{
			population = new Population{ this->params };
		}
		else
		{
			population = new Population(next_gen, this->params);
		}
		population->simulate();

		this->m_fitness_stats.push_back( population->get_best_fitness() );
		cout << " fitness: " << population->get_best_fitness() << "\n";

		next_gen = population->breed();
		delete population;

		generation_counter++;
	}
	return;	
}

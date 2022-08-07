#include "Evolution.h"

Evolution::Evolution( int generations, int species, int to_breed, int n_moves )
	: num_of_generations(generations), num_of_species(species)
{
}

void Evolution::start()
{
	Population* population = nullptr;
	vector<SnakeAI*> next_gen;

	int generation_counter = 0;

	while (generation_counter < num_of_generations)
	{
		cout << "\tGeneration: " << generation_counter << " ";
		if (population == nullptr)
		{
			population = new Population{ num_of_species, to_breed, n_moves };
		}
		else
		{
			population = new Population(next_gen);
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
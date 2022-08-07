#include "Evolution.h"

Evolution::Evolution( int generations, int species )
	: num_of_generations(generations), num_of_species(species)
{
}

void Evolution::start()
{
	Population* population = nullptr;
	vector<SnakeAI*> next_gen;

	while (num_of_generations)
	{
		if (population == nullptr)
		{
			population = new Population{ num_of_species };
		}
		else
		{
			population = new Population(next_gen);
		}
		population->simulate();

		next_gen = population->breed();
		delete population;

		num_of_generations--;
	}
	return;	
}
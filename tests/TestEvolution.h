#pragma once

#include "../snake-ai-sfml//ai_agent/include/Evolution.h"
#include "../snake-ai-sfml/ai_agent/include/EvolutionParams.h"

class TestEvolution
{
public:
	void start();
};

void TestEvolution::start()
{
	EvolutionParams p;
	p.num_generations = 100;
	p.species_in_generation = 2000;
	p.num_to_breed = 1000;
	p.lifetime = 200;

	p.moves_per_sec = 60;
	p.mutation_rate = 0.05;

	Evolution e(p);
	e.start();

	return;
}

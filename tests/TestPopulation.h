#pragma once

#include "../snake-ai-sfml/ai_agent/include/Population.h"
#include "../snake-ai-sfml/ai_agent/include/EvolutionParams.h"

class TestPopulation
{
public:

	void run_simulation();
	void prior_queue();
};

void TestPopulation::run_simulation()
{
	EvolutionParams p;
	p.num_generations = 2000;
	p.species_in_generation = 200;
	p.num_to_breed = 100;
	p.lifetime = 200;

	Population population{p};
	population.simulate();
	population.breed();

	return;
}

#define DISABLE_THAT_COD

#if !defined DISABLE_THAT_COD
/*!
* This code uses non-secure methods created specially for this case
*/
void TestPopulation::prior_queue()
{
	int n_best_to_breed = 6;
	vector<SnakeAI*> n_best_agents;

	for (int i = 0; i < n_best_to_breed; ++i)
	{
		n_best_agents.push_back( new SnakeAI );
		n_best_agents[i]->set_fitness( i * 0.1 );
	}

	auto compare = [](SnakeAI* a, SnakeAI* b) { return a->get_fitness() < b->get_fitness(); };

	priority_queue<SnakeAI*,  vector<SnakeAI*>, std::function<bool(SnakeAI*, SnakeAI*)>> min_heap(Compare);

	for (auto agent : n_best_agents)
	{
		cout << "\tfit: "<< agent->get_fitness() << "\n";
		min_heap.push(agent);
	}

	while( !min_heap.empty() )
	{
		cout << min_heap.top()->get_fitness() << "\n";
		min_heap.pop();
	}

	return;
}
#endif
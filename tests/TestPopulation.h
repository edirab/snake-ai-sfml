#pragma once

#include "../snake-ai-sfml/ai_agent/include/Population.h"

class TestPopulation
{
public:

	void run_simulation();
	void prior_queue();
};

void TestPopulation::run_simulation()
{
	Population population{10};
	population.simulate();
	population.breed();

	return;
}

//bool Compare(SnakeAI* a, SnakeAI* b)
//{
//	return a->get_fitness() < b->get_fitness();
//}

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

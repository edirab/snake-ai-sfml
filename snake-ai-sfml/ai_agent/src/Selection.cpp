#include "Selection.h"

/*
* Helper functin declared outside the class
*/
bool Compare(SnakeAI* a, SnakeAI* b)
{
	return a->get_fitness() < b->get_fitness();
}

vector<SnakeAI*> Selection::truncation(EvolutionParams& params, vector<SnakeAI*>& agents)
{
	this->m_best_fitness = 0;

	vector<SnakeAI*> n_best_agents;
	assert( params.num_to_breed <= params.species_in_generation );
	assert( params.num_to_breed > 0 );
	assert( params.species_in_generation >= 2 ); // otherwise we cannot mate them. A piar is needed

	priority_queue<SnakeAI*,  vector<SnakeAI*>, std::function<bool(SnakeAI*, SnakeAI*)>> min_heap(Compare);

	// Creating heap
	for (auto agent : agents)
	{
		this->m_best_fitness = std::max(m_best_fitness, agent->get_fitness());
		//cout << "\tfit: "<< agent->get_fitness() << "\n";
		min_heap.push(agent);
	}

	// Selection process
	for (int i = params.num_to_breed; i > 0; --i)
	{
		cout << i << ": " << min_heap.top()->get_fitness() << "\n";
		n_best_agents.push_back( min_heap.top() );
		min_heap.pop();
	}
	return n_best_agents;
}

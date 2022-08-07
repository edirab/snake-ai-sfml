#pragma once
#include <vector>

#include "Population.h"
#include "SnakeAI.h"

using std::vector;

class Evolution
{
public:
	Evolution( int generations = 20, int species = 10 );

	void start();

private:


	vector<float> m_fitness_stats;


	int num_of_generations{20};
	int num_of_species{10}; // number of individuals in each population
};


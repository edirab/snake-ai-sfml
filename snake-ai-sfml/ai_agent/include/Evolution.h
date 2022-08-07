#pragma once
#include <vector>

#include "Population.h"
#include "SnakeAI.h"

using std::vector;

class Evolution
{
public:
	Evolution( 
		int generations = 20,
		int species = N_SPECIES, 
		int to_breed = N_TO_BREED,
		int n_moves = N_MOVES_PER_SEC );

	void start();

private:


	vector<float> m_fitness_stats;


	int num_of_generations{20};
	int num_of_species{ N_SPECIES }; // number of individuals in each population
	int to_breed{ N_TO_BREED };
	int n_moves{ N_MOVES_PER_SEC }; 

};


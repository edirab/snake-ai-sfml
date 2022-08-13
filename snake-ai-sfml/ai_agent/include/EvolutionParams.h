#pragma once

#define N_SPECIES 100
#define N_TO_BREED 10
#define N_MOVES_PER_SEC 10
#define N_MOVES_ALLOWED 150

#define UNINITIALIZED -1

struct EvolutionParams
{
	int num_generations;
	int species_in_generation;
	int num_to_breed;
	int lifetime;

	int moves_per_sec;  ///< e.i. simulation speed
	float mutation_rate;
};

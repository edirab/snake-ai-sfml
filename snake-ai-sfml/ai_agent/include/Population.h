#pragma once

#include "GameWindow.h"
#include "SnakeAI.h"

#include <assert.h>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>

using std::vector;
using std::pair;
using std::priority_queue;

#define N_SPECIES 100
#define N_TO_BREED 10
#define N_MOVES_PER_SEC 10

class Population
{
public:

	/*!
	* \brief Default c-tor with default n_species value of 3
	*/
	Population(int n_species = N_SPECIES, int n_to_breed = N_TO_BREED, int moves = N_MOVES_PER_SEC);

	Population(vector<SnakeAI*> new_generation, int n_to_breed);

	~Population();

	void simulate();

	/*!
	* \brief Selects N best species and breeds them
	* \return vector of newly created agents
	*/
	vector<SnakeAI*> breed();

	float get_best_fitness();

	vector<SnakeAI*> agents; // for test purposes

private:

	//vector<SnakeAI*> agents;
	float m_best_fitness{0};

	int number_of_species{N_SPECIES};
	int n_best_to_breed{N_TO_BREED};

	float moves_per_second{N_MOVES_PER_SEC}; ///< e.i. simulation speed

	/*!
	* \brief Check is there are alive AI agents
	*/
	bool someone_still_alive();

};

bool Compare(SnakeAI* a, SnakeAI* b);

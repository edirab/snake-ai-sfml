#pragma once

#include "GameWindow.h"
#include "SnakeAI.h"

#include <assert.h>
#include <utility>
#include <vector>
#include <queue>

using std::vector;
using std::pair;
using std::priority_queue;

class Population
{
public:

	/*!
	* \brief Default c-tor with default n_species value of 3
	*/
	Population(int n_species = 3);

	Population(vector<SnakeAI*> new_generation);

	~Population();

	void simulate();

	/*!
	* \brief Selects N best species and breeds them
	* \return vector of newly created agents
	*/
	vector<SnakeAI*> breed();

	vector<SnakeAI*> agents; // for test purposes

private:

	//vector<SnakeAI*> agents;

	int number_of_species{10};
	int n_best_to_breed{2};

};

bool Compare(SnakeAI* a, SnakeAI* b);

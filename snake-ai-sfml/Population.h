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

	Population(int n_species = 3);



	void simulate();

	vector<SnakeAI*> breed();

private:

	vector<SnakeAI*> agents;

	int number_of_species{10};
	int n_best_to_breed{2};

};

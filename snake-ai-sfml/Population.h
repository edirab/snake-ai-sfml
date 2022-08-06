#pragma once

#include "GameWindow.h"
#include "SnakeAI.h"

#include <vector>

using std::vector;

class Population
{
public:

	Population(int n_species = 3);

	void simulate();

private:

	vector<SnakeAI*> agents;

	int number_of_species{3};

};


#pragma once

#include "GameWindow.h"
#include "SnakeAI.h"
#include "Selection.h"
#include "EvolutionParams.h"

#include <assert.h>
#include <utility>
#include <vector>
#include <queue>
#include <algorithm>
#include <random>

using std::vector;
using std::pair;
using std::priority_queue;
using std::random_device;
using std::mt19937;
using std::uniform_int_distribution;

class Population
{
public:

	/*!
	* \brief Default c-tor with default n_species value of 3
	*/
	Population(EvolutionParams& p);

	Population(vector<SnakeAI*> new_generation, EvolutionParams& p);

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

	EvolutionParams params;
	Selection select;

	//vector<SnakeAI*> agents;
	float m_best_fitness{0};

	/*!
	* \brief Check is there are alive AI agents
	*/
	bool someone_still_alive();

};

bool Compare(SnakeAI* a, SnakeAI* b);

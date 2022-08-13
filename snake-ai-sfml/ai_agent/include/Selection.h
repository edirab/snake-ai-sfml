#pragma once
#include <EvolutionParams.h>
#include <SnakeAI.h>
#include <vector>
#include <assert.h>
#include <queue>
#include <algorithm>

using std::vector;
using std::priority_queue;

class Selection
{
public:
	vector<SnakeAI*> truncation(EvolutionParams& p, vector<SnakeAI*>&);

	/*!
	* TODO: impl
	* \brief stohastic universal spreading
	*/
	vector<SnakeAI*> SUS(EvolutionParams& p, vector<SnakeAI*>&);

	float get_best_fitness() const { return this->m_best_fitness; }

private:
	float m_best_fitness{0};

};

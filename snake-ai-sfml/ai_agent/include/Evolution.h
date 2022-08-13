#pragma once
#include <vector>

#include "GameWindow.h"
#include "EvolutionParams.h"
#include "Population.h"
#include "SnakeAI.h"

using std::vector;

class Evolution
{
public:

	Evolution( EvolutionParams& p );

	void start();

private:
	EvolutionParams params;

	vector<float> m_fitness_stats;

};


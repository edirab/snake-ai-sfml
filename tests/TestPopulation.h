#pragma once

#include "../snake-ai-sfml/ai_agent/include/Population.h"

class TestPopulation
{
public:

	void run_simulation();

};

void TestPopulation::run_simulation()
{
	Population population{10};
	population.simulate();
	population.breed();

	return;
}

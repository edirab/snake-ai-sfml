#pragma once

#include "../snake-ai-sfml/Population.h"

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

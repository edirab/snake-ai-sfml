#pragma once

#include "../snake-ai-sfml//ai_agent/include/Evolution.h"

class TestEvolution
{
public:
	void start();
};

void TestEvolution::start()
{
	Evolution e(50, 6, 2, 100);
	e.start();

	return;
}

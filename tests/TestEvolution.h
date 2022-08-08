#pragma once

#include "../snake-ai-sfml//ai_agent/include/Evolution.h"

class TestEvolution
{
public:
	void start();
};

void TestEvolution::start()
{
	Evolution e(50, 2000, 10, 10);
	e.start();

	return;
}

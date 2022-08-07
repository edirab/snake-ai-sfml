#pragma once

#include "../snake-ai-sfml//ai_agent/include/Evolution.h"

class TestEvolution
{
public:
	void start();
};

void TestEvolution::start()
{
	Evolution e(2, 10);
	e.start();

	return;
}
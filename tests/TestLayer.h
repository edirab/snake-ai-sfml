#pragma once
#include <iostream>

#include "../snake-ai-sfml/Matrix.h"
#include "../snake-ai-sfml/Layer.h"

class TestLayer
{
public:
	void crossover();
private:
};


void TestLayer::crossover()
{
	Layer L1(8, 4);
	L1.randomize();

	Layer L2(8, 4);

	Matrix w1 = L1.get_weights();
	Matrix w2 = L2.get_weights();
	w1.print();
	w2.print();


	Matrix w3 = w1.crossover(w2);
	w3.print();
	return;
}
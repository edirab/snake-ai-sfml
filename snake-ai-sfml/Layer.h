#pragma once
#include "Matrix.h"

class Layer
{
public:
	Layer(int nInputs, int nNeurons);



private:
	Matrix* weights{nullptr};
	Matrix* biases{nullptr};

};


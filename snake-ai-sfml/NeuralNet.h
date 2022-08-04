#pragma once
#include "Layer.h"
#include <vector>

using std::vector;

class NeuralNet
{
public:
	NeuralNet(int nHiddenLayers, int nNeurons, int nInputs, int nOutputs);

	vector<double> pass(vector<int>& inputs);

private:
	Layer hidden1;
	Layer hidden2;
	Layer out;
};


#pragma once
#include "Layer.h"
#include <vector>

using std::vector;

/*!
* \brief Class represents a dense neural network with
* two fully connected hidden layers
*/
class NeuralNet
{
public:
	NeuralNet(int nHiddenLayers, int nNeurons, int nInputs, int nOutputs);

	vector<double> pass(vector<int>& inputs);

	void calc_fitness();

private:

	float fitness{0};

	Layer hidden1;
	Layer hidden2;
	Layer out;
};


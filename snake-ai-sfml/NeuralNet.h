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

	/*!
	* \brief
	* Creates net from crossovered and mutated layers
	*/
	NeuralNet(const Layer& hidden1, const Layer& hidden2, const Layer& out );

	/*!
	* \brief Makes a full pass on neural network
	* \return vector of 4 doubles
	*/
	vector<double> pass(vector<int>& inputs);

	/*!
	* \brief Performs a crossover operation layer by layer on
		two nets: current and parent
	* \return reference to a newell allocated Net object
	*/
	NeuralNet& crossover(const NeuralNet& parent);

	void calc_fitness();

private:

	// TODO: add to ctor
	float mutation_rate{0.05f}; 
	float fitness{0};

	Layer hidden1;
	Layer hidden2;
	Layer out;
};


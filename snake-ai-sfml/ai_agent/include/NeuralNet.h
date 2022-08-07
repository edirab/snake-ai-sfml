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

	/*!
	* \brief Default c-tor
	*/
	NeuralNet(int nHiddenLayers = 2, int nNeurons = 16, int nInputs = 26, int nOutputs = 4);

	/*!
	* \brief
	* Creates net from crossovered and mutated layers
	*/
	NeuralNet(const Layer& hidden1, const Layer& hidden2, const Layer& out );

	/*!
	* \brief Copy c-tor
	*/
	NeuralNet(const NeuralNet &net);

	/*!
	* \brief Makes a full pass on neural network
	* \return vector of 4 doubles
	*/
	vector<double> pass(vector<int>& inputs);

	/*!
	* \brief Performs a crossover operation layer by layer on
		two nets: current and parent
	* \return reference to a newly allocated Net object
	*/
	NeuralNet crossover(const NeuralNet& parent);

private:

	// TODO: add to ctor
	float mutation_rate{0.05f}; 

	Layer hidden1;
	Layer hidden2;
	Layer out;
};


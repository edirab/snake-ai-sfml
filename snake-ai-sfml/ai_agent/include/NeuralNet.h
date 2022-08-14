#pragma once
#include "EvolutionParams.h"
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
	NeuralNet(const EvolutionParams& p, int nHiddenLayers = 2, int nNeurons = 16, int nInputs = 26, int nOutputs = 4);

	/*!
	* \brief
	* Creates net from crossovered and mutated layers
	*/
	NeuralNet(const EvolutionParams& p, vector<Layer>& layers);

	/*!
	* \brief Copy c-tor
	*/
	NeuralNet(const EvolutionParams& p, const NeuralNet &net);

	/*!
	* \brief Makes a full pass on neural network
	* \return vector of 4 doubles
	*/
	vector<double> pass(vector<float>& inputs);

	/*!
	* \brief Performs a crossover operation layer by layer on
		two nets: current and parent
	* \return reference to a newly allocated Net object
	*/
	NeuralNet crossover(const NeuralNet& parent);

	const EvolutionParams params;

	vector<Layer> layers;

private:

};

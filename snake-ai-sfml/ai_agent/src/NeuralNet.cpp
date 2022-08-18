#include "NeuralNet.h"

NeuralNet::NeuralNet(const EvolutionParams& p, int nHiddenLayers, int nNeurons, int nInputs, int nOutputs)
	:
		params(p)
{
	layers.push_back( Layer(nNeurons, nInputs) );

	for (int i = 1; i < nHiddenLayers; ++i)
	{
		layers.push_back(  Layer(nNeurons, nNeurons) );
	}
	// the output layer
	layers.push_back( Layer(nOutputs, nNeurons) );

	for (auto& elem : layers)
	{
		elem.randomize();
	}
}

NeuralNet::NeuralNet(const EvolutionParams& p,  vector<Layer>& layers_ ) 
	: 
		params(p)
{
	layers.clear();
	for (auto& layer: layers_)
	{
		layers.push_back(layer);
	}
}

NeuralNet::NeuralNet(const EvolutionParams& p, const NeuralNet &net)
	:
		params(p)
{
	layers.clear();
	for (auto& layer: net.layers)
	{
		layers.push_back(layer);
	}
}

vector<double> NeuralNet::pass(vector<float>& inputs)
{
	//cout << "\tNet forward: \n";
	Matrix m_inputs(inputs);
	//m_inputs.print();

	for (auto& layer : layers)
	{
		m_inputs = layer.process( *m_inputs.get_mat() );
		//output.print();
	}
	return m_inputs.to_vector();
}

NeuralNet NeuralNet::crossover(const NeuralNet& parent)
{
	vector<Layer> layers_new;

	for ( int i = 0; i < layers.size(); ++i )
	{
		layers_new.push_back( layers[i].get_matrix().crossover( parent.layers[i].get_matrix() ) );
	}
	return NeuralNet(parent.params, layers_new);
}

#include "NeuralNet.h"

NeuralNet::NeuralNet(int nHiddenLayers, int nNeurons, int nInputs, int nOutputs)
	: hidden1(nInputs, nNeurons), hidden2(nNeurons, nNeurons), out(nNeurons, 4)
{
	hidden1.randomize();
	hidden2.randomize();
	out.randomize();

	hidden1.print();
	hidden2.print();
	out.print();
}

vector<double> NeuralNet::pass(vector<int>& inputs)
{
	cout << "\tNet forward: \n";
	Matrix m_inputs(inputs);
	m_inputs.print();

	cout << "output of hidden 1:\n";
	Matrix out_1 = hidden1.process( *m_inputs.get_mat() );
	out_1.print();

	cout << "output of hidden 2:\n";
	Matrix out_2 = hidden2.process( *out_1.get_mat() );
	out_2.print();

	cout << "output of net itself:\n";
	Matrix output = out.process( *out_2.get_mat() );
	output.print();

	return output.to_vector();
}
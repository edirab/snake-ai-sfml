#include "Layer.h"

Layer::Layer(int nInputs, int nNeurons)
{
	weights = new Matrix(nNeurons, nInputs);
	biases = new Matrix(nNeurons, 1);


}

MatrixXd Layer::process( MatrixXd input )
{
	MatrixXd res = *weights->get_mat() * input + *biases->get_mat();
	return res;
}

void Layer::randomize()
{
	weights->randomize();
	biases->randomize();
	return;
}

void Layer::print()
{
	cout << "\tWeights:\n";
	weights->print();
	cout << "\n\tBiases:\n";
	biases->print();
	return;
}


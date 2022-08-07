#include "Layer.h"

Layer::Layer(int nInputs, int nNeurons)
{
	weights = new Matrix(nNeurons, nInputs);
	biases = new Matrix(nNeurons, 1);
}

Layer::Layer(const Matrix& weights, const Matrix& biases)
{
	//this->weights = new Matrix(weights.get_mat()->rows(), weights.get_mat()->cols());
	this->weights = weights.clone();
	this->biases = biases.clone();
}
// FIX
Layer::Layer(const Layer& in)
{
	this->weights = in.get_weights().clone();
	this->biases = in.get_biases().clone();
}

Layer::~Layer()
{
	delete weights;
	delete biases;
}

Matrix Layer::process( MatrixXd input )
{
	Matrix in(input);
	//MatrixXd res = *weights->get_mat() * input + *biases->get_mat();
	Matrix res = *weights * in + *biases;
	res.activete();
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
// FIX
const Matrix& Layer::get_weights() const
{
	return *(this->weights);
}
const Matrix& Layer::get_biases() const
{
	return *(this->biases);
}

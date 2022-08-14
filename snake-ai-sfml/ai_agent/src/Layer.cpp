#include "Layer.h"

Layer::Layer(int nNeurons, int nInputs)
{
	matrix = new Matrix(nNeurons, nInputs + 1);
	int cols_ = matrix->get_mat()->cols();

	for (int i = 0; i < matrix->get_mat()->rows(); ++i)
	{
		matrix->set( i, cols_ - 1, 1.0f);
	}
}

Layer::Layer(const Matrix& weights_and_bias)
{
	this->matrix = weights_and_bias.clone();
}

Layer::Layer(const Layer& in)
{
	this->matrix = in.get_matrix().clone();
}

Layer::~Layer()
{
	delete matrix;
}

Matrix Layer::process( MatrixXd input )
{
	Matrix in(input);
	in.addBias();

	Matrix res = *matrix * in; // TODO: think about dims
	res.activete();
	return res;
}

void Layer::randomize()
{
	matrix->randomize();
	return;
}

void Layer::print()
{
	cout << "\tWeights:\n";
	matrix->print();
	return;
}
// FIX
const Matrix& Layer::get_matrix() const
{
	return *(this->matrix);
}

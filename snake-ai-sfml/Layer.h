#pragma once
#include "Matrix.h"

class Layer
{
public:
	/*!
	* nInputs == cols
	* nNeurons == rows of a matrix
	*/
	Layer(int nInputs, int nNeurons);
	~Layer();

	/*!
	* \brief
	* Implements a classic W * x + b equation
	*/
	Matrix process( MatrixXd input );

	void randomize();

	void print();

private:

	/*!
	* Matrix represents weights. Each row in a separate neuron 
	* with its coefficients correspondind to inputs. The number of rows 
	* equal to number of neurons
	*/
	Matrix* weights{nullptr};

	/*!
	* A column vector with biases
	*/
	Matrix* biases{nullptr};

};


#pragma once
#include "Matrix.h"

class Layer
{
public:
	/*!
	* \brief C-tor to create initial Neural Network
	* \param[in] nInputs == cols
	* \param[in] nNeurons == rows of a matrix
	*/
	Layer(int nInputs, int nNeurons);

	/*!
	* \brief
	* C-tor to create a layer from mutated and crossovered ancestors
	*/
	Layer(const Matrix& weights, const Matrix& biases);

	/*!
	* \brief
	* C-tor to create a layer from mutated and crossovered ancestors
	*/
	Layer(const Layer& in);

	~Layer();

	/*!
	* \brief Implements a classic W * x + b equation
	* \return Activated matrix
	*/
	Matrix process( MatrixXd input );

	void randomize();

	void print();

	const Matrix& get_weights() const;
	const Matrix& get_biases() const;

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


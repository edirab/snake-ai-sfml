#pragma once
#include "Matrix.h"

class Layer
{
public:
	/*!
	* \brief C-tor to create a layer: an extended matrix containing weights and a bias
	* Biases are the last column
	* \param[in] nNeurons == rows of a matrix
	* \param[in] nInputs == cols
	*/
	Layer(int nNeurons, int nInputs);

	/*!
	* \brief
	* C-tor to create a layer from mutated and crossovered ancestors
	*/
	Layer(const Matrix& weights_and_bias);

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

	const Matrix& get_matrix() const;

private:

	/*!
	* Matrix represents weights and a bias. Each row in a separate neuron 
	* with its coefficients correspondind to inputs. The number of rows 
	* equal to number of neurons.
	* The last columns is a bias
	*/
	Matrix* matrix{nullptr};

};

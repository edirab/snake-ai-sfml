#pragma once
#include <iostream>
#include <algorithm>
#include <random>

#include <Eigen/Dense>

using std::cout;
using std::max;
using Eigen::MatrixXd;

class Matrix
{
public:
	Matrix(int rows, int cols);
	~Matrix();

	/*!
	* \brief
	* Fills matrix with random floats in [-1, 1]
	*/
	void randomize();

	/*!
	* \brief
	* Applys activation function `relu` to each matrix's element
	*/
	void activete();


	void mutate(double mutation_rate);

	Matrix* crossover(Matrix& parent);

	/*!
	* RELU - rectified linear unit
	*/
	float relu(float x)
	{
       return max<float>(0,x);
	}

	void print();

	void set(int row, int col, double num);

private:
	MatrixXd* mat;
};


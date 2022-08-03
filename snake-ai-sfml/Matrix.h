#pragma once
#include <iostream>
#include <iomanip>
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

	/*!
	* \brief 
	* Changes matrix values at random positions adding normal distribution value 
	* with mean 0 and standart deviation of 0.2. Constrains to -1, 1 range
	* 
	* \param[in] mutation_rate used to calculate number of neurons to change.
	*	Set to 1 if equals to zero in case of small matrix
	*/
	void mutate(double mutation_rate);

	const MatrixXd* get_mat() const ;

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

protected:
	MatrixXd* mat;

private:
	
};


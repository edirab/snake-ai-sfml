#include "Matrix.h"

Matrix::Matrix(int rows, int cols)
{
	this->mat = new MatrixXd(rows, cols);
}

Matrix::~Matrix()
{
	delete mat;
}

void Matrix::randomize()
{
	*mat = MatrixXd::Random( mat->rows(), mat->cols() );
}

void Matrix::activete()
{
	//Eigen stores matriecs in column major style (fortran style)
	for (size_t j = 0; j < mat->cols(); ++j)
	{
		for (size_t i = 0; i < mat->rows(); ++i)
		{
			mat->operator()(i, j) = relu( mat->operator()(i, j) );
		}
	}
	return;
}

Matrix* Matrix::crossover(Matrix& parent)
{
	int nRows = this->mat->rows();
	int nCols = this->mat->cols();

	int randRow = random(0, nRows);
	int randCol = random(0, nCols);

	Matrix* child_mat = new Matrix(nRows, nCols);

	/*
	* Can be optimized. Just copy initial matrix to new one and replace elems
	*/
	for (size_t j = 0; j < nCols; ++j)
	{
		for (size_t i = 0; i < nRows; ++i)
		{
			if ((i < randRow) || (i == randRow && j <= randCol) )
			{
				child_mat->set(i, j, this->mat->operator()(i, j));
			}
			// TODO: finish
			else
			{
				//child_mat->set(i, j, //parent.oper (i, j));
			}
		}
	}
	return child_mat;
}

void Matrix::set(int row, int col, double num)
{
	this->mat->operator()(row, col) = num;
	return;
}

void Matrix::print()
{
	cout << this->mat << "\n";
	return;
}

double random(int from, int to)
{
	std::random_device rd();
	std::mt19937 rand_gen( rd );
	std::uniform_int_distribution<> distr(from, to);

	return distr( rand_gen );
}
#include "Matrix.h"

///////////////////
double random(int from, int to)
{
	std::random_device rd;
	std::mt19937 rand_gen( rd() );
	std::uniform_int_distribution<> distr(from, to);

	return distr( rand_gen );
}
///////////////////


Matrix::Matrix(int rows, int cols)
{
	this->mat = new MatrixXd(rows, cols);
	this->mat->setZero();
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
	cout << std::setprecision(2) << *(this->mat) << "\n";
	return;
}

void Matrix::mutate(double mutation_rate)
{
	MatrixXd& curr_mat = *(this->mat);

	std::random_device rd;
	std::mt19937 random_generator( rd() );
	std::uniform_int_distribution<> distr_rows(0, mat->rows() - 1);
	std::uniform_int_distribution<> distr_cols(0, mat->cols() - 1);

	std::normal_distribution<> distr_gauss(0, 0.2);

	int n_cell_to_mutate = mat->rows() * mat->cols() * mutation_rate;

	if (n_cell_to_mutate == 0 )
	{
		cout << "No cells to mutate. Setting to 1\n";
		n_cell_to_mutate = 1;
	}

	for (int i = 0; i < n_cell_to_mutate; ++i)
	{
		int rRow = distr_rows( random_generator );
		int rCol = distr_cols( random_generator );

		//mat->operator()(random_row, random_col)
		curr_mat(rRow, rCol) += distr_gauss( random_generator );

		if (curr_mat(rRow, rCol) > 1 )
		{
			curr_mat(rRow, rCol) == 1;
		} 
		else if (curr_mat(rRow, rCol) < -1)
		{
			curr_mat(rRow, rCol) = -1;
		}
	}
	return;
}

const MatrixXd* Matrix::get_mat() const 
{
	return this->mat;
}

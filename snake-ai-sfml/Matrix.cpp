#include "Matrix.h"

///////////////////
int random(int from, int to)
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

Matrix::Matrix(const Matrix& m)
{
	this->mat = new MatrixXd();
	*mat = *(m.get_mat());
}

Matrix::Matrix( vector<int>& inputs )
{
	this->mat = new MatrixXd(inputs.size(), 1);
	for (int i = 0; i < inputs.size(); i++)
	{
		(*mat)(i, 0) = inputs[i];
	}
}

Matrix::Matrix(MatrixXd& in)
{
	this->mat = new MatrixXd(in.rows(), in.cols());
	*mat = in;
}

Matrix::~Matrix()
{
	//std::cout << "Deleting mat\n";
	delete mat;
}

Matrix Matrix::operator*(Matrix& op1) const
{
	MatrixXd res = *(this->mat) *  *(op1.get_mat());
	Matrix m(res);
	return m;
}

Matrix Matrix::operator+(Matrix& op1) const
{
	MatrixXd res = *(this->mat) +  *(op1.get_mat());
	Matrix m(res);
	return m;
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

Matrix Matrix::crossover(Matrix& parent) const
{
	int nRows = this->mat->rows();
	int nCols = this->mat->cols();

	int randRow = random(0, nRows - 1);
	int randCol = random(0, nCols - 1);

	Matrix child_mat(nRows, nCols);

	/*
	* Can be optimized. Just copy initial matrix to new one and replace elems
	*/
	for (size_t j = 0; j < nCols; ++j)
	{
		for (size_t i = 0; i < nRows; ++i)
		{
			if ((i < randRow) || (i == randRow && j <= randCol) )
			{
				child_mat.set(i, j, (*mat)(i, j));
			}
			else
			{
				child_mat.set(i, j, parent.get(i, j));
			}
		}
	}
	return child_mat;
}

void Matrix::print()
{
	if (mat->cols() == 1)
	{
		MatrixXd transposed = mat->transpose();
		cout << std::setprecision(2) << "Transposed: " << transposed << "\n";
	}
	else
	{
		cout << std::setprecision(2) << *(this->mat) << "\n";
	}
	return;
}

vector<double> Matrix::to_vector()
{
	vector<double> v1;
	for (int i = 0; i < mat->rows() ; i++)
	{
		for (int j = 0; j < mat->cols(); j++)
		{
			v1.push_back( (*mat)(i, j) );
		}
	}
	return v1;
}

Matrix* Matrix::clone() const
{
	Matrix* res = new Matrix(*(this->mat));
	return res;
}

//Matrix* Matrix::operator=(const Matrix& m)
//{
//	
//}

const MatrixXd* Matrix::get_mat() const 
{
	return this->mat;
}

double Matrix::get(int row, int col)
{
	return (*mat)(row, col);
}

void Matrix::set(int row, int col, double num)
{
	this->mat->operator()(row, col) = num;
	return;
}

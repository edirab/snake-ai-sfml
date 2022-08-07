#pragma once
#include <random>
#include "Point.h"

class RandomPoint
{
public:
	/*!
	* \breif Default c-tor. Does nothing
	*/
	RandomPoint();

	/*!
	* \brief
	* \param[in] debug if set will generate same points from run to run
	*/
	explicit RandomPoint(int n_rows, int n_cols, bool debug);
	Point generate();

private:
	std::mt19937* gen_for_rows{nullptr};
	std::mt19937* gen_for_cols{nullptr};

	std::uniform_int_distribution<>* distr_rows{nullptr};
	std::uniform_int_distribution<>* distr_cols{nullptr};
};


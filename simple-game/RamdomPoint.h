#pragma once
#include <random>
#include "Point.h"

class RandomPoint
{
public:
	RandomPoint();
	explicit RandomPoint(int n_rows, int n_cols, bool debug);
	Point generate();

private:
	std::mt19937* gen_for_rows{nullptr};
	std::mt19937* gen_for_cols{nullptr};

	std::uniform_int_distribution<>* distr_rows{nullptr};
	std::uniform_int_distribution<>* distr_cols{nullptr};
};


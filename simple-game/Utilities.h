#pragma once
#include <SFML/Graphics.hpp>
#include <random>

struct Point
{
public:
	explicit Point() : x(-1), y(-1) {}
	explicit Point(int x, int y) : x(x), y(y) {}

	int x{ 0 };
	int y{ 0 };
};

class RandomPoint
{
public:
	explicit RandomPoint(int n_rows, int n_cols, bool debug);
	Point generate();

private:
	std::mt19937* gen_for_rows{nullptr};
	std::mt19937* gen_for_cols{nullptr};

	std::uniform_int_distribution<>* distr_rows{nullptr};
	std::uniform_int_distribution<>* distr_cols{nullptr};
};

void DrawLine(float x1, float y1, float x2, float y2, sf::Color color, sf::RenderWindow* window);


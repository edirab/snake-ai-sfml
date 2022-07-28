#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include "Snake.h"

struct Point
{
public:
	explicit Point() : x(-1), y(-1) {}
	explicit Point(int x, int y) : x(x), y(y) {}

	int x{ 0 };
	int y{ 0 };

	void set(int x, int y)
	{
		this->x = x;
		this->y = y;
		return;
	}

	bool operator==(const Point& p)
	{
		return ( this->x == p.x && this->y == p.y );
	}
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

void DrawRectangle(sf::RenderWindow* window, float left, float top, float width, float height, sf::Color color);

void processKeyboard(Snake &snake);

#pragma once
#include <SFML/Graphics.hpp>

struct Point
{
public:
	explicit Point(int x, int y) : x(x), y(y) {}

	int x{ 0 };
	int y{ 0 };
};

void DrawLine(float x1, float y1, float x2, float y2, sf::Color color, sf::RenderWindow* window);
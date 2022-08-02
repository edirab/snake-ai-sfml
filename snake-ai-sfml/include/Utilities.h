#pragma once
#include <SFML/Graphics.hpp>
#include <random>
#include <vector>
#include <iostream>
#include <string>

using std::cout;
using std::vector;
using std::string;

void DrawLine(sf::RenderWindow* window, float x1, float y1, float x2, float y2, sf::Color color );

void DrawRectangle(sf::RenderWindow* window, float left, float top, float width, float height, sf::Color color);

void print_ai_inputs(vector<int> inputs);

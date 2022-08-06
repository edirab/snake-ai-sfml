#pragma once
#include <SFML/Graphics.hpp>

#include "../snake-ai-sfml/NeuralNet.h"
#include "../snake-ai-sfml/SnakeAI.h"

class TestSnakeAI
{
public:
	void run();
};


void TestSnakeAI::run()
{
	//sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML works!");
	//   window->setFramerateLimit(60);

	Food food{5, 5};

	SnakeAI snake_agent(food, Point{10, 10}, Direction::Up );
	snake_agent.play();

}

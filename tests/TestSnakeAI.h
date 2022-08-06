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
	sf::RenderWindow* window = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML works!");
    window->setFramerateLimit(60);

	//sf::Event event;
 //   while (window->pollEvent(event))
 //   {
 //       if (event.type == sf::Event::Closed)
 //           window->close();
 //   }

	Food food{window, 5, 5};


	SnakeAI snake_agent( window, food, Point{10, 10}, Direction::Up );
	snake_agent.play();

}

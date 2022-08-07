#pragma once
#include <SFML/Graphics.hpp>

#include "../snake-ai-sfml/NeuralNet.h"
#include "../snake-ai-sfml/SnakeAI.h"

class TestSnakeAI
{
public:
	void run();

	void copy_ctor();

	void breed();
};


void TestSnakeAI::run()
{
	Food food{5, 5};

	SnakeAI snake_agent(food, Point{10, 10}, Direction::Up );
	snake_agent.play();

}

// FAIL
void TestSnakeAI::breed()
{
	SnakeAI* ai_1 = new SnakeAI;
	SnakeAI* ai_2 = new SnakeAI;

	SnakeAI* ai_3 = ai_1->breed(*ai_2); // FAIL here
	return;
}

void TestSnakeAI::copy_ctor()
{
	SnakeAI ai_1;
	ai_1.play();

	SnakeAI ai_2;
	ai_2.play();

	sf::Clock* clock = new sf::Clock();
	clock->restart();

	float moves_per_second{4};
	float period_ms = 1 / moves_per_second * 1000 ;

	sf::RenderWindow* window = GameWindow::get();
	while (window->isOpen())
    {
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

        if (clock->getElapsedTime().asMilliseconds() > period_ms)
        {
            clock->restart();
            window->clear();

			ai_1.step();
			ai_2.step();

			window->display();
		}
	}

	SnakeAI ai_3{ai_1};
	cout << ai_3.get_fitness() << "\n";
	return;
}
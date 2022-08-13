#pragma once
#include <SFML/Graphics.hpp>

#include "../snake-ai-sfml/ai_agent/include/NeuralNet.h"
#include "../snake-ai-sfml/ai_agent/include/SnakeAI.h"
#include "../snake-ai-sfml/ai_agent/include/EvolutionParams.h"

class TestSnakeAI
{
public:
	TestSnakeAI();

	void run();
	void copy_ctor();
	void breed();

private:
	EvolutionParams p;
};

TestSnakeAI::TestSnakeAI()
{
	p.num_generations = 2000;
	p.species_in_generation = 200;
	p.num_to_breed = 100;
	p.lifetime = 200;

	p.moves_per_sec = 5;
	p.mutation_rate = 0.05;
}


void TestSnakeAI::run()
{
	Food food{5, 5};

	SnakeAI snake_agent(p, food, Point{10, 10}, Direction::Up );
	snake_agent.play();

}

void TestSnakeAI::breed()
{
	SnakeAI* ai_1 = new SnakeAI(p);
	SnakeAI* ai_2 = new SnakeAI(p);

	SnakeAI* ai_3 = ai_1->breed(ai_2);
	return;
}

void TestSnakeAI::copy_ctor()
{
	SnakeAI ai_1(p);
	ai_1.play();

	SnakeAI ai_2(p);
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

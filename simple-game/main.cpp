#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

#include "Utilities.h"
#include "Map.h"
#include "Snake.h"
#include "tests.h"


void game()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::Clock clock;

    Map map{&window};
    Snake snake(&map, Point(10, 10), Direction::Up);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        if (snake.isAlive())
        {
            window.clear();

            map.draw_map();
            snake.draw(&window);
            window.display();

            std::this_thread::sleep_for( std::chrono::milliseconds(400) );

            processKeyboard(snake);
            snake.move();
        }
        else
        {
            // reset game
            snake.reset();
            map.reset();
        }

        sf::Time elapsed1 = clock.getElapsedTime();
        std::cout << elapsed1.asSeconds() << std::endl;
    }
    return;
}

int main()
{
    game();
    //test_food_spawn();

    return 0;
}

#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

#include "Utilities.h"
#include "Map.h"
#include "Snake.h"
#include "tests.h"

//#define sf::Keyboard::isKeyPressed isKeyPressed

void game()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    //sf::CircleShape shape(100.f);
    //shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    Map m{&window};
    Snake snake(&m, Point(10, 10), Direction::Up);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        //window.draw(shape);
        //DrawLine(0, 0, 100, 40, sf::Color::Red, &window);

        m.draw_map();
        snake.draw(&window);
        window.display();

        std::this_thread::sleep_for( std::chrono::milliseconds(1000) );

        if (sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
        {
            snake.d = Direction::Up;
        }
        else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
        {
            snake.d = Direction::Right;
        }
        else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
        {
            snake.d = Direction::Down;
        }
        else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
        {
            snake.d = Direction::Left;
        }

        snake.move();

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

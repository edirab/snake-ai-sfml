#include <SFML/Graphics.hpp>
#include <iostream>
#include "Utilities.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(200, 200), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;

    while (window.isOpen())
    {
        
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        window.draw(shape);
        DrawLine(0, 0, 100, 40, sf::Color::Red, &window);
        window.display();

        sf::Time elapsed1 = clock.getElapsedTime();
        std::cout << elapsed1.asSeconds() << std::endl;
    }

    return 0;
}
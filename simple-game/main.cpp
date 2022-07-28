#include <SFML/Graphics.hpp>
#include <iostream>
#include <thread>
#include <chrono>

#include "Utilities.h"
#include "Map.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 800), "SFML works!");
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);

    sf::Clock clock;
    Map m{&window};

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
        DrawLine(0, 0, 100, 40, sf::Color::Red, &window);
        m.draw_map();
        window.display();

        std::this_thread::sleep_for( std::chrono::milliseconds(30) );
        sf::Time elapsed1 = clock.getElapsedTime();
        std::cout << elapsed1.asSeconds() << std::endl;
    }

    return 0;
}

#include "Game.h"


void Game::init()
{
    window = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML works!");
    window->setFramerateLimit(this->fps);

	clock = new sf::Clock();
	return;
}


void Game::loop()
{
	Map map{window};
    Snake snake(&map, Point(10, 10), Direction::Up);

    while (window->isOpen())
    {
        sf::Event event;
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window->close();
        }

        if (snake.isAlive())
        {
            window->clear();

            map.draw_map();
            snake.draw(window);
            window->display();

            std::this_thread::sleep_for( std::chrono::milliseconds(10) );

            snake.processKeyboard();
            snake.move();
        }
        else
        {
            // reset game
            snake.reset();
            map.reset();
        }
        //sf::Time elapsed1 = clock->getElapsedTime();
        //std::cout << elapsed1.asSeconds() << std::endl;
    }

	return;
}

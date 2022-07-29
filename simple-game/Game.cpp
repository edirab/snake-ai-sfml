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

    float period_ms = 1 / this->moves_per_second * 1000 ;
    cout << period_ms << "\n";
    clock->restart();

    long total_frames = 0;

    while (window->isOpen())
    {


        processKeyboard_2(snake);
        if (snake.isAlive() )
        {
            if (clock->getElapsedTime().asMilliseconds() > period_ms)
            {
                cout << "Total frames: " << total_frames << " " << clock->getElapsedTime().asMilliseconds() << "\n";
                clock->restart();
                window->clear();

                snake.move();
                map.draw_map();
                snake.draw(window);
                window->display();    
                total_frames++;
                

                update_score(snake.get_length() - 1);
            }
            //processKeyboard_2(snake);
            //std::this_thread::sleep_for( std::chrono::milliseconds(5) );
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

void Game::update_score( int new_score)
{
    if (new_score > this->score)
    {
        this->score = new_score;
        string title = "Score: " + std::to_string(score);
        window->setTitle(title);
    }
    return;
}

void Game::processKeyboard_2(Snake &s)
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }

	if (sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) || sf::Keyboard::isKeyPressed(sf::Keyboard::W) )
    {
        s.d = Direction::Up;
        cout << "\tUp pressed\n";
    }
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
    {
        s.d = Direction::Right;
        cout << "\tRight pressed\n";
    }
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
    {
        s.d = Direction::Down;
        cout << "\tDown pressed\n";
    }
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
    {
        s.d = Direction::Left;
        cout << "\tLeft pressed\n";
    }
	return;
}

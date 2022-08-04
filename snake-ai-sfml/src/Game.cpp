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
    MapParams params;
    Food food{window, params, 5, 5};
    Snake snake(params, food, Point(10, 10), Direction::Up);
    Map map{window, params};

    vector<int> inputs;

    float period_ms = 1 / this->moves_per_second * 1000 ;
    //cout << period_ms << "\n";
    clock->restart();

    long total_frames = 0;

    while (window->isOpen())
    {
        processEvents(snake);

        if (!is_paused && clock->getElapsedTime().asMilliseconds() > period_ms)
        {
            //cout << "Total frames: " << total_frames << " " << clock->getElapsedTime().asMilliseconds() << "\n";
            clock->restart();
            window->clear();

            food.spawn( snake.get_body() );
            snake.move();

            if (snake.isAlive() )
            {
                map.draw();
                food.draw();
                snake.draw(window);
                window->display();    
                total_frames++;
                
                update_score(snake.get_length() - 1);

                snake.get_ai_inputs(inputs);
                print_ai_inputs(inputs);
            }
            else
            {
                // reset game
                snake.reset();
                window->setTitle("Score: 0");
            }
        }
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

void Game::processEvents(Snake &s)
{
    sf::Event event;
    while (window->pollEvent(event))
    {
        if (event.type == sf::Event::Closed)
            window->close();
    }

	if ((sf::Keyboard::isKeyPressed( sf::Keyboard::Up ) || sf::Keyboard::isKeyPressed(sf::Keyboard::W)) )
    {
        if (s.get_direction() != Direction::Up)
        {
            s.set_direction(Direction::Up);
            cout << "\tUp pressed\n";
        }
    }
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Right ) || sf::Keyboard::isKeyPressed(sf::Keyboard::D) )
    {
        if (s.get_direction() != Direction::Right)
        {
            s.set_direction(Direction::Right);
            cout << "\tRight pressed\n";
        }
    }
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Down ) || sf::Keyboard::isKeyPressed(sf::Keyboard::S) )
    {
        if (s.get_direction() != Direction::Down)
        {
            s.set_direction(Direction::Down);
            cout << "\tDown pressed\n";
        }
    }
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::Left ) || sf::Keyboard::isKeyPressed(sf::Keyboard::A) )
    {
        if (s.get_direction() != Direction::Left)
        {
            s.set_direction(Direction::Left);
            cout << "\tLeft pressed\n";
        }
    }
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::P) )
    {
        if ( is_paused == false )
        {
            is_paused = true;
        }
    }
    else if (sf::Keyboard::isKeyPressed( sf::Keyboard::C) )
    {
        if ( is_paused == true )
        {
            is_paused = false;
        }
    }
	return;
}

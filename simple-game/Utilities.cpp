#include "Utilities.h"

void DrawLine(float x1, float y1, float x2, float y2, sf::Color color, sf::RenderWindow* window)
{
    // Make an array of the two end points (an array is like a list)
    sf::Vertex points[] =
    {
        sf::Vertex(sf::Vector2f(x1, y1)),
        sf::Vertex(sf::Vector2f(x2, y2))
    };

    // Set the color of the points
    points[0].color = color;
    points[1].color = color;

    // Draw the line made by the two end points
    window->draw(points, 2, sf::Lines);
}

void DrawRectangle(sf::RenderWindow* window, float left, float top, float width, float height, sf::Color color)
{
    // Create a rectangle object
    sf::RectangleShape rectangle(sf::Vector2f(width, height));

    // Set the top left position
    rectangle.setPosition(left, top);

    // Set the color
    rectangle.setFillColor(color);

    // Draw it
    window->draw(rectangle);
}

RandomPoint::RandomPoint(int n_rows, int n_cols, bool debug)
{
    if (!debug)
    {
        std::random_device rd; // obtain a random number from hardware
        gen_for_cols = new std::mt19937(rd());// seed the generator
        gen_for_rows = new std::mt19937(rd());
    }
    else
    {
        gen_for_cols = new std::mt19937();
        gen_for_rows = new std::mt19937();
    }

    distr_rows = new std::uniform_int_distribution<>(0, n_rows - 1);
    distr_cols = new std::uniform_int_distribution<>(0, n_cols - 1);
}


Point RandomPoint::generate()
{
    Point result{ 
        distr_cols->operator()(*gen_for_cols), 
        distr_rows->operator()(*gen_for_rows), 
    };
    return result;
}

void processKeyboard(Snake &snake)
{
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
	return;
}
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

    distr_rows = new std::uniform_int_distribution<>(0, n_rows);
    distr_cols = new std::uniform_int_distribution<>(0, n_cols);
}


Point RandomPoint::generate()
{
    Point result{ 
        distr_cols->operator()(*gen_for_cols), 
        distr_rows->operator()(*gen_for_rows), 
    };
    return result;
}

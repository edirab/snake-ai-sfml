#include "Utilities.h"


void DrawLine(sf::RenderWindow* window, float x1, float y1, float x2, float y2, sf::Color color )
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

void print_ai_inputs(vector<int>inputs)
{
    vector<string> captions 
    {
        "Distance to walls:",
        "Diagonal distance to walls:",
        "Distance to food:",
        "Diagonal distance to food:",
        "Distance to body:",
        "Direction & size:",
        "To be continued:"
    };

    int counter = 0;

    for (int i = 0; i < inputs.size(); i++)
    {
        if ( i % 4 == 0)
        {
            cout << "\n" << captions[counter] << "\n\t";
            counter++;
        }
        cout << inputs[i] << " ";
    }
    return;
}

#include "GameWindow.h"

sf::RenderWindow* GameWindow::window = nullptr;

GameWindow::GameWindow() {}

sf::RenderWindow* GameWindow::get()
{
	if (window == nullptr)
	{
		window = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML works!");
		return window;
	}
	else
	{
		return window;
	}
}

//sf::RenderWindow* GameWindow::get()
//{
//	if (window == nullptr)
//	{
//		window = new sf::RenderWindow(sf::VideoMode(800, 800), "SFML works!");
//		return window;
//	}
//	else
//	{
//		return window;
//	}
//}

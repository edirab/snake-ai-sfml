#pragma once
#include <SFML/Graphics.hpp>

class GameWindow
{
public:

	GameWindow(GameWindow &other) = delete;
	void operator=(const GameWindow &) = delete;

	static sf::RenderWindow* get();
	//{
	//	if (window == nullptr)
	//	{
	//		new sf::RenderWindow(sf::VideoMode(800, 800), "SFML works!");
	//	}
	//	else
	//	{
	//		return window;
	//	}
	//}
private:
	GameWindow();
	static sf::RenderWindow* window;
};


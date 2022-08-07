#pragma once
#include <SFML/Graphics.hpp>

class GameWindow
{
public:

	GameWindow(GameWindow &other) = delete;
	void operator=(const GameWindow &) = delete;

	static sf::RenderWindow* get();

private:
	GameWindow();
	static sf::RenderWindow* window;
};

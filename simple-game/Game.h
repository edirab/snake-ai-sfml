#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>

#include "Utilities.h"
#include "Food.h"
#include "Map.h"
#include "Snake.h"


class Game
{
public:
	int fps{60};

	void init();

	void loop();

private:
	sf::RenderWindow* window{nullptr};
	sf::Clock* clock{nullptr};

};


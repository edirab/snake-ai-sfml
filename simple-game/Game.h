#pragma once
#include <SFML/Graphics.hpp>
#include <thread>
#include <chrono>
#include <string>


#include "Utilities.h"
#include "Food.h"
#include "Map.h"
#include "Snake.h"

using std::string;

class Game
{
public:
	int fps{60};
	int score{-1};

	float moves_per_second{1}; ///< number of Snake's moves e.i. speed

	void init();

	void loop();
	void update_score( int new_score);

private:
	sf::RenderWindow* window{nullptr};
	sf::Clock* clock{nullptr};

	void processEvents(Snake &s);
};

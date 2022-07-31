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

	float moves_per_second{4}; ///< number of Snake's moves per second e.i. speed

	void init();

	void loop();
	void update_score( int new_score);

private:
	sf::RenderWindow* window{nullptr};
	sf::Clock* clock{nullptr};
	bool is_paused{false};

	/*!
	* Method for processing keyboard events
	* \param[in] reference to snake object
	* \param[out] snake's updated direction
	*/
	void processEvents(Snake &s);
};

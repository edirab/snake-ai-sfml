#pragma once
#include "Map.h"
#include "Food.h"
#include "Snake.h"
#include "NeuralNet.h"
#include<algorithm>
#include <vector>

using std::vector;
using std::max_element;
using std::find;
using std::distance;

class SnakeAI
{
public:
	SnakeAI(
		sf::RenderWindow* window,
		Food f, Point startint_position, Direction d
	);

	SnakeAI(
		sf::RenderWindow* window,
		Food &f, Point& startint_position, Direction d,
		NeuralNet& net
	);

	Snake snake;
	NeuralNet brain;

	float fitness();

	void play();

	void draw();

private:
	sf::RenderWindow* window{nullptr};

	Food food;

	vector<int> inputs;

	float m_fitness{0};
	int n_moves_left{600};
	
	/*!
	* \brief Makes decision about further snake direction
	* \details Gets input for brain from snake'a API, calls brain.pass()
	* and chooses an index of maximum element in output array
	*/
	void make_decision();

	void calc_fitness();
};


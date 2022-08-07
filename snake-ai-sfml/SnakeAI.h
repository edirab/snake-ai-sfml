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

	/*!
	* \brief Default c-tor
	* Food pos, startin pos and direction are random
	*/
	SnakeAI( );

	/*!
	* \brief Creates a new agent from child net brain
	*/
	SnakeAI(NeuralNet& net);

	SnakeAI(
		Food f, Point startint_position, Direction d
	);

	SnakeAI(
		Food &f, Point& startint_position, Direction d,
		NeuralNet& net
	);

	bool operator<(const SnakeAI& x)
	{
		return this->m_fitness > x.m_fitness;
	}

	bool operator<(const SnakeAI* x)
	{
		return this->m_fitness > x->m_fitness;
	}

	Snake snake;
	NeuralNet brain;

	/*!
	* \brief Performs one step of simulation
	* \details Makes sequential calls of
	* food.spawn, make_decision, move and draws objects
	*/
	void step();

	/*!
	* \brief plays game itself until agent is alive and n_moves_left is not zero
	* Always draws objects
	*/
	void play();

	void draw();

	SnakeAI* breed(const SnakeAI& parent);

	float get_fitness();

private:
	sf::RenderWindow* window{nullptr};

	Food food;

	vector<int> inputs;

	float m_fitness{0};
	int n_moves_left{30};
	bool m_draw{true};
	
	/*!
	* \brief Makes decision about further snake direction
	* \details Gets input for brain from snake'a API, calls brain.pass()
	* and chooses an index of maximum element in output array
	*/
	void make_decision();

	void calc_fitness();
};


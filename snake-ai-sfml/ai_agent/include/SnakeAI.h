#pragma once
#include "Map.h"
#include "Food.h"
#include "Snake.h"
#include "NeuralNet.h"
#include "EvolutionParams.h"

#include <algorithm>
#include <vector>
#include <math.h>

using std::vector;
using std::max_element;
using std::find;
using std::distance;
using std::powf;


class SnakeAI
{
public:

	/*!
	* \brief Default c-tor
	* Food pos, startin pos and direction are random
	*/
	SnakeAI( EvolutionParams& p );

	/*!
	* \brief Creates a new agent from child net brain
	*/
	SnakeAI( EvolutionParams& p, NeuralNet& net );

	SnakeAI( EvolutionParams& p, 
		Food f, Point startint_position, Direction d );

	SnakeAI( EvolutionParams& p,
		Food &f, Point& startint_position, Direction d,
		NeuralNet& net );

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

	/*!
	* \brief Creates new object via crossover of curr and parent brains
	* Allocates memory!
	*/
	SnakeAI* breed(const SnakeAI* parent);

	float get_fitness();
	int get_lifetime() const { return this->m_lifetime; }

	void  set_fitness(float f) {this->m_fitness = f;}; // for test purposes

private:
	EvolutionParams params;

	sf::RenderWindow* window{nullptr};

	Food food;

	vector<float> inputs;

	float m_fitness{0};
	int m_lifetime{0};

	bool m_draw{true};
	
	/*!
	* \brief Makes decision about further snake direction
	* \details Gets input for brain from snake'a API, calls brain.pass()
	* and chooses an index of maximum element in output array
	*/
	void make_decision();

	void calc_fitness();
};


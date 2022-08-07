#include "Population.h"

Population::Population(int n_species) 
	: number_of_species(n_species)
{
	//agents.resize(number_of_species);
	for (int i = 0; i < number_of_species; ++i)
	{
		SnakeAI* agent = new SnakeAI();
		agents.push_back(agent);
	}
}

Population::Population(vector<SnakeAI*> new_generation)
{
	this->agents = new_generation;
	this->number_of_species = new_generation.size();
}

Population::~Population()
{
	for (auto elem : agents)
	{
		delete elem;
	}
}

void Population::simulate()
{
	sf::Clock* clock = new sf::Clock();
	clock->restart();

	float moves_per_second{4};
	float period_ms = 1 / moves_per_second * 1000 ;

	sf::RenderWindow* window = GameWindow::get();
	while (window->isOpen())
    {
		sf::Event event;
		while (window->pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window->close();
		}

        if (clock->getElapsedTime().asMilliseconds() > period_ms)
        {
            clock->restart();
            window->clear();

			for (int i = 0; i < agents.size(); ++i)
			{
				agents[i]->step();
			}
			window->display();
		}
	}
	return;
}

/*
* Helper functin declared outside the class
*/
bool Compare(SnakeAI* a, SnakeAI* b)
{
	return a->get_fitness() < b->get_fitness();
}

vector<SnakeAI*>Population::breed()
{
	vector<SnakeAI*> new_generation;
	vector<SnakeAI*> n_best_agents;

	assert( n_best_to_breed <= number_of_species );
	assert( n_best_to_breed > 0 );
	assert( number_of_species >= 2 ); // otherwise we cannot mate them. A piar is needed

	priority_queue<SnakeAI*,  vector<SnakeAI*>, std::function<bool(SnakeAI*, SnakeAI*)>> min_heap(Compare);

	// Creating heap
	for (auto agent : agents)
	{
		cout << "\tfit: "<< agent->get_fitness() << "\n";
		min_heap.push(agent);
	}

	// Selection process
	for (int i = n_best_to_breed; i >= 0; --i)
	{
		cout << i << ": " << min_heap.top()->get_fitness() << "\n";
		n_best_agents.push_back( min_heap.top() );
		min_heap.pop();
	}

	/*
	* mate agents cicularly. 1st + 2nd, 3nd + 3rd, nth + 1-st
	* Repetative pairs may occur in case of 
	* n_best_to_breed is less then number_of_species
	*/
	SnakeAI* new_agent;
	int counter = number_of_species;
	int curr_index = 0;

	while( counter )
	{
		if ( counter == n_best_agents.size() - 1 )
		{
			new_agent = agents[ counter ]->breed( agents[0] );
		}
		else
		{
			new_agent = agents[ counter ]->breed( agents[ counter+1 ] );
		}
		new_generation.push_back(new_agent);
		counter--;
	}
	return new_generation;
}

Cahnges
	- extended class Food
	- added drawing grid and spawn_food methods
	- added random Point generator
	- 

Changes:
	- added getters to Map class
	- added draw and movement methods to Snake class
	- keybord processing

Changes
	- added reset methods to Map and Snake
	- collision detection with walls
	- added set method to Point class

Changes:
	- fixed bug with one snake movement delay
	- fixed food respawn glitch
	- added score to window title
	- process keybord method moved from Snake to Game class
	- added varaible for adjusting snake's speed

Changes:
	- minor refactoring
	- cleanup of diagnostic messages
	- fixed bug with score after reset

Changes:
	- partially developed an api to get input for AI.
	Need to add diagonal distance to snake's body
	- added function for printing net input parameters
	- partially tested

Changes:
	- Added class Layer with initial structure
	- Created method Matrix::mutate
	- Added helper function to generate random ints in range
	- Added unit tests for Matrix class

Changes:
	- Added and tested methods to Layer class
	- Finished Snake API
	- Added mat getter to Matrix class
	- Unit tests moved to separate test class

Changes:
	- updated Layer::process
	- added destructor ~Layer
	- added NeuralNet class
	- added helper function to convert std::vector to Matrix object
	- NeuralNet::pass tested prelimenary

Changes:
	- Another c-tor for Layer class added, getters added
	- Added Matrix::clone()
	- Added TestLayer class, crossover tested. To be updated
	- Methods in Matrix reorganized

Changes:
	- Added copy c-top to Layer class
	- Added const qualifiers to some Matrix methods
	- NeuralNet: c-tor from layers and crossover method were implemented
	- Refactoring of tests/main.cpp

Changes:
	- Added SnakeAI class
	- Added test for SnakeAI
	- Slightly changes signature of Snake's methods
	- Added copy c-tor for NeuralNet, tests refactored

Changes:
	- Added Population class
	- Added step() method to Snake class 
		in order to simulate several AIs simultaneously
	- Added another c-tor and randomize() method to Snake class
	- Added test to Population class

Changes:
	- First succesful run of TestPopulation!
	- Fixed bugs in c-tors

Changes:
	- Added Population::breed()
	- Added SnakeAI::SnakeAI(NeuralNet& net)
	- Added SnakeAI::breed(), need to debug
	- Created new c-tor from NeuralNet for SnakeAI
	- overloaded less operator in SnakeAI, need to debug
	- New tests created

Changes:
	- Added Evolution class
	- Created parametric c-tor and destructor for Population
	- Population::breed reworked

Changes:
	- Fixed bug in Population::breed(), added get_best_fitness()
	- Created TestEvolution class
	- Fixed bug with balck window, added SnakeAI::someone_is_alive method

Changes:
	- Fixed bug (typo) in NeuralNet c-tors

Changes:
	- Altered get_fitness() function
	- Commented out debug output
	- Changed initial snake position. It's center now
	- Fixed bug in get_fitness function()
	
Cahnges:
	- Added EvolutionParams struct to store evolution parameters in a centralized way
	- Evolution, Population and SnakeAI classes c-tors abapted to use EvolutionParams
	- Tests are also updated to be properly compiled

Changes:
	- NeuralNetwork c-tors updated
	- removed redundunt n_noves_left from SnakaAI
	- Fixed bug in simulation period calculation
	- Tests fixed

Changes:
	- selection part moved to a separate Selection class:
		truncation selsction reworked: mating is now random,
		added getter for best fitness
	- best snake from prev generation is now preserved
	- added clone method to SnakeAI
	
Changes:
	- now inputs are 1.0f / param
	- fixed bug in get_ai_inputs() method

Changes:
	- Layer isnow a single extended matrix: last column is a bias
	- Reworked Layer class
	- Added addBias method to Matrix class
	- Reworker NeuralNet c-tors. Need to be vrified

1. Draw grid
2. Draw snake
3. Draw food

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

### TODO: 
- Rename project to Snake-AI-SFML

- Develop an API to get inputs for a neural network:
	8 rays from snake's head, eacn ray gievs 3 numbers:
	- distance to wall
	- distance to food (-1 if not encountered)
	- distance to snake's body (-1 if not encountered)
plus additional input for the length
plus current direction (in case if snake can kill itsef by changind dir to 180*)



### Done:

X rework randomizing algorith: food items lay on diagonal y = -x. 
	Consider another random distribution (e.i. normal distribution for 2D points)
+ add some borders to snake's body segments. Draw a line along all bricks
X disable move in reverse direction. Need to make a dicision: either to prohibit such
	behavior or consider it as death
+ rework food spawning: chack for snake body parts
+ mark snake's head with another color
+ upgrade move method: collision detection with walls and with snake itself
+ add score to the screen
+ enable snake growing
+ add speed parameter, tune delay in main cycle to 60 fps

### Idea #1
- Когда будет реализована и отлажена нейросеть, можно реализовать алгоритм борьбы с 
переобучением/запоминаним. Например, drop out

### Idea #2
- Можно реализовать обработку кадра с помощью компьютерного зрения.
Т.е. змейка будет получать не вектор из 25-и параметров, в кадр ака скрин с экрана,
который она должна проанализировать и принять решение куда двигаться. Можно добавить
шумы к кадру, чтобы посложнее было. 
	Цель: повспоминать средства библиотки OpenCV, бинаризацию, поик контуров и т.д.

### Idea #3
- Можно добавить стены! Тогда алгоритм зрения необходимо будет доработать для
распознавания стен


### Notes:
	что требуется, радзработать алгоритм обучения с подкреплением.
	Это один из видов обучения с учителем, где учителем выступает среда.

	Агент действует в среде, среда даёт агенту обратную связь.
	Агент корректирует своё поведение

	Для QLearning есть часть исследования среды

### Изучение проекта SnakeAI

- в качестве функции активации используется relu = max(0, x)
- случайные значения берутся в диапазоне от -1 до 1
- нейросеть представлена таблицей (класс Matrix)
- crossover - перестановка случайных строк таблиц 

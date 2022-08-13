
### Problem:
Алгоритм не обучается. Прошло 20 поколений по 100 особей в каждом, никакого прогресса.

Что можно попробовать:
1. Зафиксируй положение змейки и еды, посмотри будет ли какой прогресс
+ 2. Скопируй ф-ию фитнеса из проекта-примера. Повтори симуляцию
+ 3. посмотри каково  начальное положение змейки и еды в проекте-примере
4. Сравни с тем как быстро обучается змейка в проекте-примере.
	Сколько особей в популяции? (2000)
	На каком поколении начинает появляться порядок? (где-то с 4-5-го)
	Сколько особей используется для размножения?
+ 5. Выведи в консоль значения ф-ии фитнеса в проекте-примере

Змейка начинает из центра всегда. Квадраит еды произволен.
В поколении 2000 особей.
Лучшая особь прошлого поколения точно переходит в новое поколение.

Если у чувака работает и ты видищь своими глазами результат, то имеет смысл 
скопировать полностью сначала, а уже потом разбираться как и что устроено.
```
  void calculateFitness() {  //calculate the fitness of the snake
     if(score < 10) {
        fitness = floor(lifetime * lifetime) * pow(2,score); 
     } else {
        fitness = floor(lifetime * lifetime);
        fitness *= pow(2,10);
        fitness *= (score-9);
     }
  }
```
Вполне возможно, что мой способ расчёта расстояния (шахматное расстояние) - говно 
и так лучше никогда больше не делать. Нейронки любят числа, и числа с плавающей 
запятой несут больше информации чем целые. Между двумя целыми бесконечное число float'ов


В проекте-примере змейка из 3-х элементов уже на первом поколении.
Возможно, отсутствие тела путает нейросеть. 

### TODO: 
	
- Display the only one snake, the best from previous generation
- Thorely test snake api. 
	Make a separape project
	Darw lines of vision/.
	Add interactivity: move snake and food piece with mouse

- Change breeding starategy: if you have pop of 2000 and selecting 100 to breed
	it will be only 5% of initial population. Breeing in pairs not good, mate them randomly
	
- Create a clear and centralized way to set these params:
	+ num of generations
	+ num of species in a population
	+ num of best to breed
	+ game speed
	- mutation rate

- Maybe it would be better to create a standalone method Population::selection()

- SnakeAI: generate random direction.
	Add food c-tor which accepts color,
	
- Add parameter wether to draw a snake or not
- how to dump a net to file and resore back?
- Add multithreading for quick computations


### Done:
+ Fix Population constructor: n_moves is not equal to moves_per_sec (e.i. game speed!) It's a BUG!
+ Create helper struct to setup all important params at once
+ Initial snake length for evolution shuold be 3 items
+ Create Snake API v2 
	+ floats
	+ initial values are zeros
	+ proper distance calculation
+ Debug "Invalid food pos" (normal behaviour, won't be fixed)
+ Save best fitness from a certain Population. Add getter
+ Rework Population::breed algorithm. We should get in total number_of_species
+ Debug priority_queue issues
+ Debug and fix ~~copy c-tor of Layer class~~ crossover in NeuralNet
X solve Eigen randomizing issues. Test (double check)
+ Create default c-tor for Food
+ SnakeAI: generate random food pos, snake pos
+ Design Population class
+ Too many parameters in c-tors: Make singletons for MapPArams and game window
+ design fitness function
+ Design SnakeAI class: snake itself, neural brain, numreb of steps, fitness
+ Add class Net
+ dont forget to add destructors everywhere
+ Rename project to Snake-AI-SFML
+ Develop an API to get inputs for a neural network:
	8 rays from snake's head, eacn ray gievs 3 numbers:
	- distance to wall
	- distance to food (-1 if not encountered)
	- distance to snake's body (-1 if not encountered)
	plus additional input for the length
	plus current direction (in case if snake can kill itsef by changind dir to 180*)

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

### Выяснить
когда стоит возвращать ссылку из функции. Например, создаём новый объект 
в куче внутри метода, возвращаем ссылку на него. Как будет уничтожаться такой объект?


### In Notepad++
Ctrl + Shift + Arrow - move line\block
Alt + Shifl + Arrow - multiple cursor. In VS also


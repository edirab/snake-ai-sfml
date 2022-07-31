
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

TODO: 
- Rename project to Snake-AI-SFML


Done:

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

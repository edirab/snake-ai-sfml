
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

TODO: 
- upgrade move method: collision detection with walls and with snake itself
- rework food spawning: chack for snake body parts
- mark snake's head with another color
- disable move in reverse direction. Need to make a dicision: either to prohibit such
	behavior or consider it as death
- Rename project to Snake-AI-SFML

Done:
+ add score to the screen
+ enable snake growing
+ add speed parameter, tune delay in main cycle to 60 fps
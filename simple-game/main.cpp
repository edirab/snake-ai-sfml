#include <SFML/Graphics.hpp>
#include <iostream>

//#include "Utilities.h"
//#include "Map.h"
//#include "Snake.h"
#include "Game.h"
#include "tests.h"


void game()
{
    Game g;
    g.init();
    g.loop();

    return;
}

int main()
{
    game();
    //test_food_spawn();

    return 0;
}

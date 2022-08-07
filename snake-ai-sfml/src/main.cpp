#include <SFML/Graphics.hpp>
#include <iostream>
#include "Game.h"


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

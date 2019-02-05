#include "game.h"

#include <iostream>


int main()
{
    bool goahead = true;

    do
    {
        DungeonCrawl::drawMap();
        DungeonCrawl::movePlayer();
        goahead = DungeonCrawl::checkPlayer();
    }while(goahead);

    DungeonCrawl::drawMap();

    return 0;
}

#include "game.h"

#include <iostream>

namespace DungeonCrawl {

enum class Fields : char
{
    Field = '.',
    Tree  = 'T',
    Exit = 'X'
};

static const int ROW{7};
static const int COL{10};
static Fields map[ROW][COL]
{
    {Fields::Field, Fields::Tree,  Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field},
    {Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field},
    {Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Tree,  Fields::Field, Fields::Field, Fields::Field},
    {Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field},
    {Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Tree,  Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field},
    {Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Tree,  Fields::Field, Fields::Field, Fields::Field},
    {Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Field, Fields::Exit},
};

struct {
    char symbol{'G'};
    int x{0};
    int y{0};
} static Player{};

void drawMap()
{
    std::cout.clear();

    for (int i=0;i<ROW;++i)
    {
        for (int j=0;j<COL;++j)
        {
            if((i == Player.y) && (j == Player.x))
            {
                std::cout << Player.symbol << ' ';
            }
            else
            {
                std::cout << static_cast<char>(map[i][j]) << ' ';
            }
        }
        std::cout << std::endl;
    }

    std::cout << std::endl;
}

void movePlayer()
{
    char command;
    std::cin >> command;

    switch (command) {
    case 'w':
        if(Player.y-1 >= 0)
        {
            --Player.y;
        }
        else {
            std::cout << "Cannot move!" << std::endl;
        }
        break;
    case 's':
        ++Player.y;
        break;
    case 'a':
        --Player.x;
        break;
    case 'd':
        ++Player.x;
        break;
    default:
        break;
    }
}

bool checkPlayer()
{
    bool goahead = true;

    switch (map[Player.y][Player.x]) {
    case Fields::Tree:
        Player.symbol = '=';
        goahead = false;
        break;
    default:
        break;
    }

    return goahead;
}

} // namespace DungeonCrawl

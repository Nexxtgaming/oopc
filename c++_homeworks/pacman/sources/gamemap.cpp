#include "../headers/gamemap.h"

GameMap::GameMap()
{
}

int GameMap::getCellValue(int x, int y) const
{

    if (x == BOARD_X || y == BOARD_Y){
        return -1;

    }
    if (x > BOARD_X || y == BOARD_Y){
        return 0;
    }
    if( x < 0 || y < 0) return -1;

    return this->board[x][y];
}

#include "../headers/gamemap.h"

GameMap::GameMap()
{
}

int GameMap::getCellValue(int x, int y) const
{
    if (x < 0 || y < 0)
        return 0;
    if (x >= BOARD_X || y >= BOARD_Y)
        return 0;
    return this->board[x][y];
}

void GameMap::drawBoard(QPainterPath &wallsPath, QPainterPath &otherPath)
{
    for (int i = 0; i < BOARD_X; i++)
    {
        for (int j = 0; j < BOARD_Y; j++)
        {
            qreal x = MARGIN_X + i * SIZE;
            qreal y = MARGIN_Y + j * SIZE;
            if (this->board[i][j] == 0)
            {
                wallsPath.addRect(x, y, SIZE, SIZE);
            }
            else
            {
                otherPath.addRect(x, y, SIZE, SIZE);
            }
        }
    }
}

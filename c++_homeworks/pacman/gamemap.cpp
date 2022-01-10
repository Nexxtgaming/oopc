#include "gamemap.h"

GameMap::GameMap()
{

}

int GameMap::getCellValue(int x, int y)const
{
    return this->board[x][y];

}

void GameMap::drawBoard(QPainterPath& wallsPath, QPainterPath& otherPath)
{
    for(int i = 0; i < BOARD_X; i++ ){
        for(int j = 0; j < BOARD_Y; j++){
            qreal x = MARGIN_X + i * SIZE;
            qreal y = MARGIN_Y + j * SIZE;
            if(this->board[i][j] == 0){
                wallsPath.addRect(x, y, SIZE, SIZE);

            }else{
                otherPath.addRect(x, y, SIZE, SIZE);
            }

        }
    }
}

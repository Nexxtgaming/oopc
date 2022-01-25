#include "../headers/pacman.h"

Pacman::Pacman(GameMap *gameMap) : Entity("resources/pacman-right.png", gameMap)
{
    this->posX = 19;
    this->posY = 13;
    this->points = 0;
    setPos(posY * SIZE + MARGIN_Y, posX *SIZE + MARGIN_X);
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left && isMovePossible("left"))
    {
        this->posY--;
        if(posY < 0) posY = BOARD_Y -1;
        
        int newY = MARGIN_Y + posY * SIZE;
        setPos(newY, y());
        direction = "left";
        setPixmap(QPixmap("resources/pacman-left.png").scaled(SIZE, SIZE));
    }
    else if (event->key() == Qt::Key_Right && isMovePossible("right"))
    {
        this->posY++;
        if(posY == BOARD_Y) posY = 0;
        int newY = MARGIN_X + posY * SIZE;
        setPos(newY, y());
        direction = "right";
        setPixmap(QPixmap("resources/pacman-right.png").scaled(SIZE, SIZE));
    }
    else if (event->key() == Qt::Key_Up && isMovePossible("up"))
    {
        this->posX--;
        if(posX < 0 ) posX = BOARD_X - 1;
        int newX = MARGIN_Y + posX * SIZE;
        setPos(x(), newX);
        direction = "up";
        setPixmap(QPixmap("resources/pacman-up.png").scaled(SIZE, SIZE));
    }
    else if (event->key() == Qt::Key_Down && isMovePossible("down"))
    {
        this->posX++;
        if(posX == BOARD_X) posX = 0;
        int newX = MARGIN_Y + posX * SIZE;
        setPos(x(), newX);
        direction = "down";
        setPixmap(QPixmap("resources/pacman-down.png").scaled(SIZE, SIZE));
    }
}

int Pacman::getPoint(int mode, GameTimer &gameTimer)
{
    if (gameMap->getCellValue(posX, posY) == 2)
    {
        points += SMALL_POINT;
        gameMap->board[posX][posY]--;
    }
    if (gameMap->getCellValue(posX, posY) == 3)
    {
        points += BIG_POINT;
        gameMap->board[posX][posY]--;
        mode = 3;
        gameTimer.startRecording();
    }
    return mode;
}

int Pacman::getPosX()
{
    return this->posX;
}

int Pacman::getPosY()
{
    return this->posY;
}

int Pacman::getScore()
{
    return this->points;
}
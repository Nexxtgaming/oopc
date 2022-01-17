#include "../headers/pacman.h"

Pacman::Pacman() : Entity("../resources/pacman-right.png")
{
    this->posX = 20;
    this->posY = 14;
    this->points = 0;
}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    if (event->key() == Qt::Key_Left && isMovePossible("left"))
    {
        this->posX--;
        int newX = MARGIN_X + posX * SIZE;
        setPos(newX, y());
        // setPixmap(QPixmap()) left
    }
    else if (event->key() == Qt::Key_Right && isMovePossible("right"))
    {
        this->posX++;
        int newX = MARGIN_X + posX * SIZE;
        setPos(newX, y());
        // setPixmap(QPixmap()) right
    }
    else if (event->key() == Qt::Key_Up && isMovePossible("up"))
    {
        this->posY--;
        int newY = MARGIN_Y + posY * SIZE;
        setPos(x(), newY);
        // setPixmap(QPixmap()) up
    }
    else if (event->key() == Qt::Key_Down && isMovePossible("down"))
    {
        this->posY++;
        int newY = MARGIN_Y + posY * SIZE;
        setPos(x(), newY);
        // setPixmap(QPixmap()) down
    }
    getPoint();
}

void Pacman::getPoint()
{
    if (gameManager->gameMap->getCellValue(posX, posY) == 2)
    {
        points++;
        gameManager->gameMap->board[posX][posY]--;
    }
    if (gameManager->gameMap->getCellValue(posX, posY) == 3)
    {
        points += 10;
        gameManager->gameMap->board[posX][posY]--;
        gameManager->mode = 3;
        gameManager->startRecording();
    }
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
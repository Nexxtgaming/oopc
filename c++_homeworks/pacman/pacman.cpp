#include "pacman.h"

Pacman::Pacman() : Entity("./pacman-right.png")
{
    posX = 20;
    posY = 14;

}

void Pacman::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        this->posX--;
        int newX = MARGIN_X + posX * SIZE;
        setPos(newX, y());

    }else if(event->key() == Qt::Key_Right){
        this->posX++;
        int newX = MARGIN_X + posX * SIZE;
        setPos(newX, y());

    }else if(event->key() == Qt::Key_Up){
        this->posY--;
        int newY = MARGIN_Y + posY * SIZE;
        setPos(x(), newY);

    }else if(event->key() == Qt::Key_Down){
        this->posY++;
        int newY = MARGIN_Y + posY * SIZE;
        setPos(x(), newY);

    }

}

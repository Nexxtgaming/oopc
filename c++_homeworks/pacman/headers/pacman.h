#ifndef PACMAN_H
#define PACMAN_H

#include "config.h"
#include <QKeyEvent>
#include "entity.h"

class Pacman : public Entity
{
    Q_OBJECT
    int points;
    void getPoint();

public:
    Pacman();
    void keyPressEvent(QKeyEvent *event);
    int getPosX();
    int getPosY();
    int getScore();
    friend class GameManager;
    friend class Enemy;
};

#endif // PACMAN_H

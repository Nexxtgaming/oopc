#pragma once 
#include "entity.h"
#include "config.h"
#include <QKeyEvent>
#include "gamemanager.h"

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


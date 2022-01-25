#pragma once
#include "entity.h"
#include "direction.h"
#include "config.h"
#include "gametimer.h"
#include <QKeyEvent>
class Pacman : public Entity
{
    Q_OBJECT
private:
    int points;
    Direction direction;
    int getPoint(int mode, GameTimer &gameTimer);

public:
    Pacman(GameMap *gameMap);
    void keyPressEvent(QKeyEvent *event);
    int getPosX();
    int getPosY();
    int getScore();
    friend class GameManager;
    friend class Enemy;
};

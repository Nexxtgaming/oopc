#ifndef PACMAN_H
#define PACMAN_H

#include "../headers/entity.h"
#include "../headers/config.h"
#include <QKeyEvent>
#include "../headers/gamemap.h"
#include "../headers/enemy.h"

class Pacman : public Entity
{
    int points;
    void getPoint();

public:
    Pacman();
    void keyPressEvent(QKeyEvent *event);
    int getPosX();
    int getPosY();
    int getScore();
    friend class Enemy;
};

#endif // PACMAN_H

#pragma once 

#include "entity.h"
#include <QTimer>
#include <QObject>
#include <vector>
#include "direction.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "pacman.h"

class Pacman;

class Enemy : public Entity
{
    Q_OBJECT
private:
    std::string name;
    bool isDead = false;
    void eatPlayer();
    Vector2 chaseTarget;
    Vector2 scatterTarget;
    Direction approachFrom;
    std::vector<Direction> getPossibleDirections();
    Direction chooseDirection(std::vector<Direction> directions);

public:
    Enemy(QString imagePath, std::string name);
    ~Enemy();
public slots:
    void move();
};


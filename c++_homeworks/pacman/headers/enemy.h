#ifndef ENEMY_H
#define ENEMY_H

#include <QTimer>
#include <QObject>
#include "entity.h"
#include <vector>
#include "direction.h"
#include <math.h>
#include <stdlib.h>
#include <time.h>
#include "gamemanager.h"

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

#endif // ENEMY_H

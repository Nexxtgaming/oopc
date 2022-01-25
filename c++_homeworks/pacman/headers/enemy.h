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

class GameMap;
class Enemy : public Entity
{
    Q_OBJECT
private:
    Pacman *player;
    std::string name;
    bool isOrange;
    Vector2 chaseTarget;
    Vector2 scatterTarget;
    Direction approachFrom;
    std::vector<Direction> getPossibleDirections();
    Direction chooseDirection(std::vector<Direction> directions, int mode);
    void initValues(bool isConstructor);
    void setPlayer(Pacman *player);
    void eatPlayer(int mode);
    void overlap();

public:
    Enemy(QString imagePath, std::string name, Pacman *player);
    int move(int mode, int timeElapsed);
    friend class GameManager;
};

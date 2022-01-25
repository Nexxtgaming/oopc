#pragma once
#include <iostream>
#include "config.h"
#include <QObject>
#include <QTimer>
#include "gamemap.h"
#include "pacman.h"
#include "entity.h"
#include "enemy.h"
#include "gametimer.h"
#include "square.h"
#include "point.h"
#include <QGraphicsScene>
#include "vector"
#include <QGraphicsTextItem>
#include <string>

class GameManager : public QObject
{
    Q_OBJECT

private:
    int enemyNumber = 0;
    int mode;
    bool gameOver = false;
    GameTimer *gameTimer;
    std::vector<Point *> points;
    QGraphicsTextItem * text;
    void updateScene();


public:
    GameMap *gameMap;
    Pacman *player;
    Enemy *enemies[ENEMY_NUMBER];
    GameManager(QObject *parent = nullptr);

    void addEnemies();
    bool isGameOver();
    void drawGameMap(QGraphicsScene * scene);
    friend class Enemy;
    friend class Pacman;
    friend class Entity;
public slots:
    void gameLoop(QGraphicsScene * scene);
};

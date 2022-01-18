#pragma once
#include <iostream>
#include "config.h"
#include <QElapsedTimer>
class Pacman;
class GameMap;
class Enemy;

class GameManager
{
private:
    GameMap *gameMap;
    Pacman *player;
    Enemy *enemies[ENEMY_NUMBER];
    int enemyNumber = 0;
    int mode = 1;
    bool gameOver = false;
    QElapsedTimer timer;
    int lastRecordedTime = 0;
    void startRecording();
    int getTimeElapsed();

public:
    GameManager(GameMap *gamemap, Pacman *player);
    void addEnemy(Enemy *enemyTable[ENEMY_NUMBER]);
    bool isGameOver();
    friend class Enemy;
    friend class Pacman;
    friend class Entity;
};

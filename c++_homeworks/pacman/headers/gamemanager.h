#pragma once
#include <iostream>
#include "pacman.h"
#include "gamemap.h"
#include "enemy.h"
#include "entity.h"
#include "config.h"
#include <QElapsedTimer>

class GameManager
{
private:
    Pacman *player;
    GameMap *gameMap;
    Enemy **enemies[ENEMY_NUMBER];
    int enemyNumber = 0;
    int mode = 1;
    bool gameOver = false;
    QElapsedTimer timer;
    int lastRecordedTime = 0;
    void startRecording();
    int getTimeElapsed();

public:
    GameManager(GameMap *gamemap, Pacman *player);
    void addEnemy(Enemy **enemyTable[ENEMY_NUMBER]);
    bool isGameOver();
    friend class Enemy;
    friend class Pacman;
    friend class Entity;
};

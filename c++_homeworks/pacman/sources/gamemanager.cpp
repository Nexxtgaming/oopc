#include "../headers/gamemanager.h"

GameManager::GameManager(GameMap *gameMap, Pacman *player)
{
    this->gameMap = gameMap;
    gameMap->gameManager = this;
    this->player = player;
    player->gameManager = this;
    this->timer.start();
}

void GameManager::addEnemy(Enemy *enemyTable[ENEMY_NUMBER])
{
    for (int i = 0; i < ENEMY_NUMBER; i++)
    {
        enemies[i] = enemyTable[i];
        enemies[i]->gameManager = this;
    }
}

void GameManager::startRecording()
{
    lastRecordedTime = timer.elapsed();
}

int GameManager::getTimeElapsed()
{
    int timeElapsed = timer.elapsed() - lastRecordedTime;
    return timeElapsed;
}

bool GameManager::isGameOver()
{
    return gameOver;
}

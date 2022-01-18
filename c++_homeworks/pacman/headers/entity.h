#pragma once 

#include <QObject>
#include <QGraphicsPixmapItem>
#include "config.h"
#include "gamemanager.h"
#include "gamemap.h"

class GameMap;
class GameManager;

class Entity : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    int posX;
    int posY;
    GameManager *gameManager;
    bool isMovePossible(std::string direction);

public:
    explicit Entity(QString imagePath, QObject *parent = nullptr);
    friend class GameManager;
};


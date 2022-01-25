#pragma once

#include <QObject>
#include <QGraphicsPixmapItem>
#include "config.h"
#include "gamemap.h"
class Entity : public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
protected:
    QPixmap image;
    int posX;
    int posY;
    bool isDead;
    GameMap *gameMap;
    bool isMovePossible(std::string direction);

public:
    explicit Entity(QString imagePath, GameMap *gameMap, QObject *parent = nullptr);
    friend class GameManager;
};

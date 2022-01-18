#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QGraphicsPixmapItem>
#include "gamemap.h"
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

#endif // ENTITY_H

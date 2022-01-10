#ifndef ENEMY_H
#define ENEMY_H

#include <QTimer>
#include <QObject>
#include "entity.h"

class Enemy : public Entity
{
    Q_OBJECT
public:
    Enemy(QString imagePath);
public slots:
    virtual void move();
};

#endif // ENEMY_H

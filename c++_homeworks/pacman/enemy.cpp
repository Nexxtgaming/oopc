#include "enemy.h"

Enemy::Enemy(QString imagePath) : Entity(imagePath)
{
    QTimer * timer = new QTimer();
    connect(timer, SIGNAL(timeout()),this, SLOT(move()));
    timer->start(50);


}

#ifndef ENTITY_H
#define ENTITY_H

#include <QObject>
#include <QGraphicsPixmapItem>

class Entity : public QObject, public  QGraphicsPixmapItem
{
    Q_OBJECT
    int posX;
    int posY;
    bool isMovePossible(std::string direction);
public:
    explicit Entity(QString imagePath, QObject *parent = nullptr);

signals:

};

#endif // ENTITY_H

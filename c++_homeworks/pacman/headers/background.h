#ifndef BACKGROUND_H
#define BACKGROUND_H

#include <QWidget>
#include "../headers/gamemap.h"
#include <QPainter>
#include <QPainterPath>

class BackGround : public QWidget
{
    Q_OBJECT
public:
    explicit BackGround(QWidget *parent = nullptr);
    void drawBackGround(GameMap &gamemap);

signals:
};

#endif // BACKGROUND_H

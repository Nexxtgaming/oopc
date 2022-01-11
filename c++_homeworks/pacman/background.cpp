#include "background.h"

BackGround::BackGround(QWidget *parent) : QWidget(parent)
{


}

void BackGround::drawBackGround(GameMap * gamemap)
{
    QPainter p(this);
    p.setRenderHint(QPainter::Antialiasing);
    QPainterPath wallsPath;
    QPainterPath otherPath;
    gamemap->drawBoard(wallsPath, otherPath);

    p.fillPath(wallsPath, Qt::blue);
    p.drawPath(wallsPath);

    p.fillPath(otherPath, Qt::black);
    p.drawPath(otherPath);


}

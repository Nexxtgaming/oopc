
#include <QApplication>
#include <QGraphicsScene>
#include "pacman.h"
#include "gamemap.h"
#include "config.h"
#include "background.h"
#include <QGraphicsView>

int main(int argc, char *argv[])
{



    QApplication a(argc, argv);
    QGraphicsScene * scene = new QGraphicsScene ();
    Pacman * pacman = new Pacman();
    BackGround * background = new BackGround();
    GameMap * gamemap = new GameMap();
    background->drawBackGround(gamemap);

    pacman->setFlag(QGraphicsItem::ItemIsFocusable);
    scene->addItem(pacman);
    scene->addWidget(background);
    pacman->setFocus();
    QGraphicsView * view = new QGraphicsView (scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(SCENE_WIDTH, SCENE_HEIGHT);
    scene->setSceneRect(0,0, SCENE_WIDTH, SCENE_HEIGHT);




    return a.exec();
}

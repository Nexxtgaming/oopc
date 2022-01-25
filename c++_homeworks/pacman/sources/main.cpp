
#include <QApplication>
#include <QGraphicsScene>
#include "../headers/pacman.h"
#include "../headers/gamemap.h"
#include "../headers/config.h"
#include "../headers/gamemanager.h"
#include <QGraphicsView>
#include <QGraphicsTextItem> 

int main(int argc, char *argv[])
{

    QApplication a(argc, argv);
    QGraphicsScene *scene = new QGraphicsScene();
    GameManager *gameManager = new GameManager();

    gameManager->player->setFlag(QGraphicsItem::ItemIsFocusable);
    gameManager->drawGameMap(scene);
    scene->addItem(gameManager->player);
    gameManager->player->setFocus();
    QGraphicsView *view = new QGraphicsView(scene);
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->show();
    view->setFixedSize(SCENE_WIDTH, SCENE_HEIGHT);
    scene->setSceneRect(0, 0, SCENE_WIDTH, SCENE_HEIGHT);
    gameManager->gameLoop();

    return a.exec();
}

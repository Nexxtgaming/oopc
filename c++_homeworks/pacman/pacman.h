#ifndef PACMAN_H
#define PACMAN_H

#include "entity.h"
#include "config.h"
#include <QKeyEvent>

class Pacman : public Entity
{
public:
    Pacman();
    void keyPressEvent(QKeyEvent * event);

};

#endif // PACMAN_H

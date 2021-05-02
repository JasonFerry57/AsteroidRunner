#include "MyRect.h"
#include "Bullet.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>
void MyRect::keyPressEvent(QKeyEvent *event)
{
    if(event->key() == Qt::Key_Left){
        setPos(x()-10,y());
    }
    else if(event->key() == Qt::Key_Right){
        setPos(x()+10,y());
    }
    else if(event->key() == Qt::Key_Up){
        setPos(x(),y()-10);
    }
    else if(event->key() == Qt::Key_Down){
        setPos(x(),y()+10);
    }
    else if(event->key() == Qt::Key_Space){
        //create a bullet for the player
        Bullet * bullet = new Bullet();
        //sets the position of the bullet
        bullet->setPos(x(),y());
        //adds the bullet to the scene
        scene()->addItem(bullet);
    }
}

#include <QApplication>
#include <QGraphicsScene>
#include "MyRect.h"
#include <QGraphicsView>

/*
 -QGraphicsScene makes the map or the world
 -QGraphicsItem makes the player
 -QGraphicsView
*/

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // create the scene
    QGraphicsScene * scene = new QGraphicsScene();

    //Create an item to put into the scene
    MyRect * player = new MyRect();
    player -> setRect(0,0,100,100);

    //add the item to the scene
    scene->addItem(player);

    //make the player focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    QGraphicsView * view = new QGraphicsView(scene);
    //initalises the set scene that you want to visualise
    //view->setScene(scene);

    //makes the scroll bars not show at all when objects go off the screen
    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    //fixes the size of the screen
    view->setFixedSize(800,600);
    //sets the scene to be the same size of the screen
    scene->setSceneRect(0,0,800,600);
    //sets the player to the middle and bottom of the scene
    player->setPos(view->width()/2 - player->rect().width()/2, view->height() - player->rect().height());

    return a.exec();
}

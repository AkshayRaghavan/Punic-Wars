#include "Player1.h"
#include <QGraphicsScene>
#include <QKeyEvent>
#include "Tower.h"
#include "Bullet.h"
#include "Ships.h"
#include <QDebug>

Player1::Player1(QGraphicsItem * parent): QGraphicsPixmapItem(parent){
    select=false;
    t=nullptr;
    setPixmap(QPixmap(":/Resources/images/sel_tow.jpg"));

}

void Player1::keyPressEvent(QKeyEvent *event) {
    if(select == true) {        //tower is selected
        if(event->key() == Qt::Key_Return) {
            select=false;
            setPixmap(QPixmap(":/Resources/images/sel_tow.jpg"));
        }
        else if(event->key() == Qt::Key_Right) {
            if(t->x()<1450)
                t->setPos(t->x()+50,t->y());
        }
        else if(event->key() == Qt::Key_Down) {
            if(t->y()<500)
                t->setPos(t->x(),t->y()+50);
        }
        else if(event->key() == Qt::Key_Left) {
            if(t->x()>0)
                t->setPos(t->x()-50,t->y());
        }
        else if(event->key() == Qt::Key_Up) {
            if(t->y()>0)
                t->setPos(t->x(),t->y()-50);
        }
    }
    else {                      //no towers are selected
        if(event->key() == Qt::Key_Return) {
            select=true;
            t=new Tower();
            t->setPos(0,0);
            scene()->addItem(t);
            setPixmap(QPixmap(":/Resources/images/towB.jpg"));
            //scene()->addItem(p);
        }
        else if(event->key() == Qt::Key_D) {
            Ships * ship = new Ships();
            ship->setPos(50,50);
            ship->setRotation(40);
            scene()->addItem(ship);
        }
    }
}


#include "Bullet.h"
#include <QTimer>
#include <QGraphicsScene>
#include <QList>
#include "Enemy.h"
#include "Game.h"

extern Game * game;

Bullet::Bullet(): QObject(), QGraphicsRectItem(){
    //drew the rect
    setRect(0,0,10,50);

    // connect
    QTimer * timer = new QTimer();
    connect(timer,SIGNAL(timeout()),this,SLOT(move()));

    timer->start(50);
}

void Bullet::move()
{
    //if bullet colliides with enemy, deatroy both
    QList<QGraphicsItem *> colliding_items = collidingItems();
    for(int i=0,n = colliding_items.size() ; i<n; ++i ){
        if (typeid(*(colliding_items[i]))==typeid(Enemy)){
            //increase the score
            game->score->increase();

            //remove them both
            scene()->removeItem(colliding_items[i]);
            scene()->removeItem(this);
            //delete them both
            delete colliding_items[i];
            delete this;
            return;

        }
    }

    //move bullet up
    setPos(x(),y()-10);
    if(pos().y()+rect().height() <0){
        scene()->removeItem(this);
        delete this;
        qDebug() << "bullet deleted";
    }
}

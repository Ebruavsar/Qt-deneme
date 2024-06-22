
#include <QApplication>
#include "MyRect.h"
#include <QGraphicsScene>
#include <QGraphicsView>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //create a scane(sahne)
    QGraphicsScene * scane =new QGraphicsScene();

    //create an item to put into the scene(öğe)
    MyRect * player = new MyRect();
    player->setRect(0,0,100,100);

    //add the item to the scene
    scane->addItem(player);

    //make rect focusable
    player->setFlag(QGraphicsItem::ItemIsFocusable);
    player->setFocus();

    //add a view
    QGraphicsView * view =new QGraphicsView(scane);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();
    view->setFixedSize(800,600);
    scane->setSceneRect(0,0,800,600);

    player->setPos(view->width()/2,view->height()-player->rect().height());

    return a.exec();
}

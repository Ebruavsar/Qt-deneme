
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
    MyRect * rect = new MyRect();
    rect->setRect(0,0,100,100);

    //add the item to the scene
    scane->addItem(rect);

    //make rect focusable
    rect->setFlag(QGraphicsItem::ItemIsFocusable);
    rect->setFocus();

    //add a view
    QGraphicsView * view =new QGraphicsView(scane);

    view->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    view->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

    view->show();

    return a.exec();
}

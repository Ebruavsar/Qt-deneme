#include "Score.h"
#include <QFont>

Score::Score(QGraphicsItem *parent):QGraphicsTextItem(parent)
{
    //initialize the score to 0
    score=0;

    //draw the text
    setPlainText(QString("score: ")+QString::number(score));
    setDefaultTextColor(Qt::AutoColor);
    setFont(QFont("times",16));

}

void Score::increase()
{
    score++;
    setPlainText(QString("score: ")+QString::number(score));


}

int Score::getScore()
{
    return score;
}

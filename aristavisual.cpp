#include "aristavisual.h"

AristaVisual::AristaVisual(NodoVisual*nv, int p)
{
    final = nv;
    peso = new QGraphicsTextItem(QString::number(p));
}

void AristaVisual::setInicio(QPointF p1)
{
    setLine(p1.x(),p1.y(),line().x2(),line().y2());
    setFinal(QPointF(line().x2(),line().y2()));
    QPoint end(line().x2(),line().y2());
    QPoint middle((p1.x()+end.x())/2,(p1.y()+end.y())/2);
    peso->setPos(middle.x(),middle.y());
}

void AristaVisual::setFinal(QPointF p2)
{
    setLine(line().x1(),line().y1(),p2.x(),p2.y());
//    QPointF f=p2;
//    if(line().x1()<p2.x())
//    {
//        f.setX(p2.x()-15);
//    }else{
//        f.setX(p2.x()+15);
//    }
//    if(line().y1()<p2.y())
//    {
//        f.setX(p2.y()-15);
//    }else{
//        f.setX(p2.y()+15);
//    }
//    setLine(line().x1(),line().y1(),f.x(),f.y());
}




Arrow::Arrow(NodoVisual *nv,int p) : AristaVisual(nv,p)
{
//    l1.setLine(
//    setTransformOriginPoint(p1);
    //    setRotation(20);
    line1 = new QGraphicsLineItem();
    line2 = new QGraphicsLineItem();
}

void Arrow::setInicio(QPointF p1)
{
    AristaVisual::setInicio(p1);

    QPoint end(line().x2(),line().y2());

    l1.setP2(end);
    l2.setP2(end);

    QPoint middle((p1.x()+end.x())/2,(p1.y()+end.y())/2);
    QPoint middle2((end.x() + middle.x())/2,(end.y() + middle.y())/2);
    QPoint middle3((end.x() + middle2.x())/2,(end.y() + middle2.y())/2);

//    l1.setP2(middle3);
//    l2.setP2(middle3);
//    setLine(p1.x(),p1.y(),middle3.x(),middle3.y());

    l1.setP1(QPoint(middle2.x(),middle2.y()));
    l2.setP1(QPoint(middle2.x(),middle2.y()));

    line1->setTransformOriginPoint(end);
    line1->setRotation(20);
    line1->setLine(l1);

    line2->setTransformOriginPoint(end);
    line2->setRotation(-20);
    line2->setLine(l2);
}

void Arrow::setFinal(QPointF p2)
{
    AristaVisual::setFinal(p2);
}

#include "aristavisual.h"

AristaVisual::AristaVisual(NodoVisual*nv)
{
    final = nv;
}

void AristaVisual::setInicio(QPointF p1)
{
    setLine(p1.x(),p1.y(),line().x2(),line().y2());
    setFinal(QPointF(line().x2(),line().y2()));
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




Arrow::Arrow(NodoVisual *nv) : AristaVisual(nv)
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

    l1.setP1(QPoint((end.x() + (p1.x()+end.x())/2)/2,(end.y() + (p1.y()+end.y())/2)/2));
    l2.setP1(QPoint((end.x() + (p1.x()+end.x())/2)/2,(end.y() + (p1.y()+end.y())/2)/2));

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

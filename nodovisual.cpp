#include "nodovisual.h"

NodoVisual::NodoVisual()
{
    setAcceptDrops(true);
    setRect(0, 0, 50, 50);
    setPos(0,0);
    azul.setColor(Qt::blue);
    QBrush rojo(Qt::red);
    setPen(azul);
    setBrush(rojo);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    text = new QGraphicsTextItem("11");
    QPointF p(pos().x()+rect().width()*0.2,pos().y()+rect().height()*0.2);
    text->setPos(p);
}

NodoVisual::NodoVisual(Nodo *n)
{
    nodo=n;
    setAcceptDrops(true);
    setRect(0, 0, 50, 50);
    setPos(0,0);
    azul.setColor(Qt::blue);
    QBrush rojo(Qt::red);
    setPen(azul);
    setBrush(rojo);
    setFlag(QGraphicsItem::ItemIsMovable, true);
    text = new QGraphicsTextItem(nodo->valor);
    QPointF p(pos().x()+rect().width()*0.2,pos().y()+rect().height()*0.2);
    text->setPos(p);

//    aristas.push_back(new AristaVisual(NULL));
}

void NodoVisual::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QGraphicsEllipseItem::paint(painter,option,widget);
    QPointF p(pos().x()+rect().width()*0.2,pos().y()+rect().height()*0.2);
    text->setPos(p);

    for(int i=0;i<aristas.size();i++)
    {
        QPointF p1(pos().x()+rect().width()*0.5,pos().y()+rect().height()*0.5);
        aristas[i]->setInicio(p1);
        QPointF p2(aristas[i]->final->pos().x()+rect().width()*0.5,aristas[i]->final->pos().y()+rect().height()*0.5);
        aristas[i]->setFinal(p2);
//        aristas[i]->paint(painter,option,widget);
    }
//    text->paint(painter,option,widget);
}


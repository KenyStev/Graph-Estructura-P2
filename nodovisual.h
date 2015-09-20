#ifndef NODOVISUAL_H
#define NODOVISUAL_H
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QPen>
#include <QBrush>
#include <vector>
#include <iostream>
#include "nodo.h"
#include "aristavisual.h"

using namespace std;

class NodoVisual : public QGraphicsEllipseItem
{
public:
    Nodo *nodo;
    vector<AristaVisual*> aristas;
    QGraphicsTextItem *text;
    NodoVisual();
    NodoVisual(Nodo*);

    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
               QWidget *widget =0);

private:
    QPen azul;
};

#endif // NODOVISUAL_H

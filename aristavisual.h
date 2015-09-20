#ifndef ARISTAVISUAL_H
#define ARISTAVISUAL_H

#include <QGraphicsLineItem>

class NodoVisual;

class AristaVisual : public QGraphicsLineItem
{
public:
    NodoVisual *final;
    AristaVisual(NodoVisual*);
    virtual void setInicio(QPointF);
    virtual void setFinal(QPointF);
};

#endif // ARISTAVISUAL_H


#ifndef ARROW
#define ARROW

class Arrow : public AristaVisual
{
public:
    QLine l1,l2;
    QGraphicsLineItem *line1, *line2;
    Arrow(NodoVisual*);

    virtual void setInicio(QPointF);
    virtual void setFinal(QPointF);
};

#endif

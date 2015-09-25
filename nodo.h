#ifndef NODO
#define NODO
#include <iostream>
#include <QString>
#include "arista.h"

using namespace std;

class Nodo
{
public:
    Nodo *adyacente;
    Arista *aristas;
    QString valor;

    Nodo(QString v)
    {
        valor = v;
        aristas = NULL;
        adyacente = NULL;
    }

    void addArista(Nodo*n,int p)
    {
        if(!aristas)
        {
            aristas = new Arista(p,n);;
            return;
        }
        Arista*tmp=aristas;
        while (tmp->adyacente) {
            tmp = tmp->adyacente;
        }
        tmp->adyacente = new Arista(p,n);
    }

    void addArista(Arista*a)
    {
        if(!aristas)
        {
            aristas = a;
            return;
        }
        Arista*tmp=aristas;
        while (tmp->adyacente) {
            tmp = tmp->adyacente;
        }
        tmp->adyacente = a;
    }
};

#endif // NODO_H

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
};

#endif // NODO_H

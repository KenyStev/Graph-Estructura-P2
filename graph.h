#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "nodo.h"
#include "list.h"

using namespace std;

class Graph
{
public:
    Nodo *actual;
    bool dirigido;

    Graph(bool);

    void addNodo(Nodo *nuevo);
    void addArista(Nodo *inicio,Nodo*final,int peso);
    Nodo* search(QString n);
    Nodo* search(QString n, Nodo*Actual);

private:
    List *checked;
};

#endif // GRAPH_H

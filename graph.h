#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include <vector>
#include <map>
#include "nodo.h"
#include "list.h"
#include "queue.h"

using namespace std;

enum dijkstra{
    POS, PESO, CHECKED, PATH
};

class Graph
{
public:
    Nodo *actual;
    bool dirigido;
    vector<AristaND*> aristasND;

    Graph(bool);

    bool addNodo(Nodo *nuevo);
    bool addArista(Nodo *inicio,Nodo*final,int peso);
    Nodo* search(QString n);
    Nodo* search(QString n, Nodo*Actual);

//    void Dijkstra(Nodo*);
//    void Floyd(Nodo*);
    vector<QString> Dijkstra(Nodo*);
    vector<QString> Floyd(Nodo*);
    Graph* Prim(Nodo*);
    Graph* Kruskal(Nodo*);

    int size();
    int index(Nodo*);
    int getFinIndex(int*,Nodo*);

    void falsearNodos();
    Nodo* getAt(int);

private:
    List *checked;
    int Size;

    int INF = 99999;

    AristaD* searchAristaD(Nodo*,Nodo*);
    AristaND* searchAristaND(Nodo*,Nodo*);
};

#endif // GRAPH_H

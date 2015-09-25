#ifndef GRAPHGRAPH_H
#define GRAPHGRAPH_H
#include "graph.h"

#include <QMainWindow>
#include <iostream>
class QGraphicsScene;

#include "nodovisual.h"

using namespace std;

namespace Ui {
class GraphGraph;
}

class GraphGraph : public QMainWindow
{
    Q_OBJECT

public:
    explicit GraphGraph(bool,QWidget *parent = 0);
    ~GraphGraph();

    Graph *g;
    vector<NodoVisual*> *nodos,*nodos_prim,*nodos_kruskal;

    NodoVisual* search(Nodo*);
    NodoVisual* search(vector<NodoVisual*>*&,Nodo*);

    void setVisualArista(Graph*&,vector<NodoVisual*>*&,QGraphicsScene*&,Nodo*,Nodo*,int);
    void setVisualNode(QGraphicsScene*&,NodoVisual*);

private slots:
    void on_btnAdd_clicked();

    void on_btnCreate_clicked();

    void on_btnDijkstra_clicked();

    void on_btnPrim_clicked();

    void on_btnFloyd_clicked();

private:
    Ui::GraphGraph *ui;
    QGraphicsScene *scene,*scene_Dijkstra,*scene_Floyd,*scene_Kruskal,*scene_Prim;

    void fillLists();
};

#endif // GRAPHGRAPH_H

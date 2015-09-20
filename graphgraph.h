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
    vector<NodoVisual*> nodos;

    NodoVisual* search(Nodo*);

private slots:
    void on_btnAdd_clicked();

    void on_btnCreate_clicked();

private:
    Ui::GraphGraph *ui;
    QGraphicsScene *scene;
};

#endif // GRAPHGRAPH_H

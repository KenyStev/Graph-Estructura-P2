#include "graphgraph.h"
#include "ui_graphgraph.h"

GraphGraph::GraphGraph(bool directed, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphGraph)
{
    ui->setupUi(this);
    g = new Graph(directed);
    scene = new QGraphicsScene();

//    Nodo *n = new Nodo("1"),
//         *a = new Nodo("2"),
//         *b = new Nodo("3"),
//         *c = new Nodo("4"),
//         *d = new Nodo("5");

//    g->addNodo(n);
//    g->addNodo(a);
//    g->addNodo(b);
//    g->addNodo(c);
//    g->addNodo(d);

//    g->addArista(n,a,4);
//    g->addArista(n,b,2);
//    g->addArista(n,c,3);
//    g->addArista(n,d,5);

//    g->addArista(b,a,7);
//    g->addArista(b,c,5);

//    g->addArista(d,a,1);
//    g->addArista(d,c,4);

//    cout<<g->actual->valor.toStdString()<<endl;
//    cout<<g->actual->aristas->final->valor.toStdString()<<endl;

//    Nodo* cc = g->search("4");
//    cout<<cc->valor.toStdString()<<endl;

    ui->gView->setScene(scene);
}

GraphGraph::~GraphGraph()
{
    delete ui;
}

NodoVisual *GraphGraph::search(Nodo *s)
{
    for (int i = 0; i < nodos.size(); ++i) {
        if(nodos[i]->nodo==s)
            return nodos[i];
    }
    return NULL;
}

void GraphGraph::on_btnAdd_clicked()
{
    QString t = ui->newNodo->text();
    Nodo*n = new Nodo(t);
    g->addNodo(n);

    NodoVisual *nuevo = new NodoVisual(n);
    scene->addItem(nuevo);
    scene->addItem(nuevo->text);
    nodos.push_back(nuevo);
}

void GraphGraph::on_btnCreate_clicked()
{
    if(g->dirigido)
    {
        NodoVisual *p1 = search(g->search(ui->fromNodo->text()));
        NodoVisual *p2 = search(g->search(ui->toNodo->text()));
        Arrow *ar = new Arrow(p2);
        p1->aristas.push_back(ar);

        scene->addItem(ar);
        scene->addItem(ar->line1);
        scene->addItem(ar->line2);
    }else{
        NodoVisual *p1 = search(g->search(ui->fromNodo->text()));
        NodoVisual *p2 = search(g->search(ui->toNodo->text()));
        AristaVisual *ar = new AristaVisual(p2);
        p1->aristas.push_back(ar);

        scene->addItem(ar);
    }
}

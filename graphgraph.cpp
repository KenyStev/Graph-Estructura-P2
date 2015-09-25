#include "graphgraph.h"
#include "ui_graphgraph.h"

GraphGraph::GraphGraph(bool directed, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::GraphGraph)
{
    ui->setupUi(this);
    g = new Graph(directed);
    scene = new QGraphicsScene();
    scene_Dijkstra = new QGraphicsScene();
    scene_Floyd = new QGraphicsScene();
    scene_Kruskal = new QGraphicsScene();
    scene_Prim = new QGraphicsScene();
/*
    Nodo *n0 = new Nodo("0"),
         *n1 = new Nodo("1"),
         *n2 = new Nodo("2");
//         *c = new Nodo("4"),
//         *d = new Nodo("5");

    g->addNodo(n0);
    g->addNodo(n1);
    g->addNodo(n2);
//    g->addNodo(c);
//    g->addNodo(d);

    g->addArista(n0,n1,10);
    g->addArista(n0,n2,2);
    g->addArista(n2,n1,1);*/
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
    fillLists();
}

void GraphGraph::on_btnCreate_clicked()
{
    Nodo* ni = g->search(ui->fromNodoC->currentText());
    Nodo* nf = g->search(ui->toNodoC->currentText());
    NodoVisual *p1 = search(ni);//ui->fromNodo->text()));
    NodoVisual *p2 = search(nf);//toNodo->text()));
    int peso = ui->pesoArista->text().toInt();
    if(g->dirigido)
    {
        Arrow *ar = new Arrow(p2,peso);
        p1->aristas.push_back(ar);

        scene->addItem(ar);
        scene->addItem(ar->line1);
        scene->addItem(ar->line2);
        scene->addItem(ar->peso);

        g->addArista(ni,nf,peso);//mostrar mensaje
    }else{
        AristaVisual *ar = new AristaVisual(p2,peso);
        p1->aristas.push_back(ar);

        scene->addItem(ar);
        scene->addItem(ar->peso);

        g->addArista(ni,nf,peso);//mostrar mensaje
    }
}

void GraphGraph::fillLists()
{
    ui->fromNodoC->clear();
    ui->toNodoC->clear();
    ui->origenNodo_DijFlo->clear();
    ui->origenNodo_KrusPri->clear();
    Nodo *tmp = g->actual;
    while (tmp) {
        ui->fromNodoC->addItem(tmp->valor);
        ui->toNodoC->addItem(tmp->valor);
        ui->origenNodo_DijFlo->addItem(tmp->valor);
        ui->origenNodo_KrusPri->addItem(tmp->valor);
        tmp = tmp->adyacente;
    }
}

void GraphGraph::on_btnDijkstra_clicked()
{
    Nodo*origen = g->search(ui->origenNodo_DijFlo->currentText());
    vector<QString> data = g->Dijkstra(origen);//g->actual);
    scene_Dijkstra->clear();
    for(int i=0;i<data.size();i++)
    {
        QGraphicsTextItem *item = new QGraphicsTextItem();
        item->setPlainText(data[i]);
        item->setPos(0,i*50);
        scene_Dijkstra->addItem(item);
    }
    ui->gView->setScene(scene_Dijkstra);
}

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

    nodos = new vector<NodoVisual*>;
    nodos_prim = new vector<NodoVisual*>;
    nodos_kruskal = new vector<NodoVisual*>;
/*
    Nodo *n0 = new Nodo("0"),
         *n1 = new Nodo("1"),
         *n2 = new Nodo("2"),
         *n3 = new Nodo("3"),
         *n4 = new Nodo("4"),
         *n5 = new Nodo("5"),
         *n6 = new Nodo("6"),
         *n7 = new Nodo("7");
//         *c = new Nodo("4"),
//         *d = new Nodo("5");

    g->addNodo(n0);
    g->addNodo(n1);
    g->addNodo(n2);
    g->addNodo(n3);
    g->addNodo(n4);
    g->addNodo(n5);
    g->addNodo(n6);
    g->addNodo(n7);
//    g->addNodo(c);
//    g->addNodo(d);

    g->addArista(n0,n1,7);
    g->addArista(n0,n2,5);
    g->addArista(n0,n3,7);
    g->addArista(n1,n2,9);
    g->addArista(n1,n3,8);
    g->addArista(n1,n5,6);
    g->addArista(n3,n7,7);
    g->addArista(n4,n6,5);
    g->addArista(n5,n6,9);
    g->addArista(n5,n7,2);
    g->addArista(n6,n7,7);
    fillLists();*/
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
    for (int i = 0; i < nodos->size(); ++i) {
        if((*nodos)[i]->nodo->valor==s->valor)
            return (*nodos)[i];
    }
    return NULL;
}

NodoVisual *GraphGraph::search(vector<NodoVisual *> *&nodos, Nodo *s)
{
    for (int i = 0; i < nodos->size(); ++i) {
        if((*nodos)[i]->nodo->valor==s->valor)
            return (*nodos)[i];
    }
    return NULL;
}

void GraphGraph::setVisualNode(QGraphicsScene *&s,NodoVisual *nuevo)
{
    s->addItem(nuevo);
    s->addItem(nuevo->text);
}

void GraphGraph::setVisualArista(Graph*&gr,vector<NodoVisual*>*&n,QGraphicsScene*&s,Nodo *ni, Nodo *nf, int peso)
{
    NodoVisual *pos1 = search(ni);//ui->fromNodo->text()));
    NodoVisual *pos2 = search(nf);//toNodo->text()));

    NodoVisual *p1 = search(n,ni);//ui->fromNodo->text()));
    NodoVisual *p2 = search(n,nf);//toNodo->text()));

    p1->setPos(pos1->pos());
    p2->setPos(pos2->pos());
//    int peso = ui->pesoArista->text().toInt();
    if(gr->dirigido)
    {
        cout<<"entro a dirigido"<<endl;
        Arrow *ar = new Arrow(p2,peso);
        p1->aristas.push_back(ar);

        s->addItem(ar);
        s->addItem(ar->line1);
        s->addItem(ar->line2);
        s->addItem(ar->peso);

        cout<<"salio a dirigido"<<endl;

//        g->addArista(ni,nf,peso);//mostrar mensaje
    }else{
        cout<<"entro a no dirigido"<<endl;
        AristaVisual *ar = new AristaVisual(p2,peso);
        p1->aristas.push_back(ar);

        s->addItem(ar);
        s->addItem(ar->peso);

        cout<<"salio a no dirigido"<<endl;

//        g->addArista(ni,nf,peso);//mostrar mensaje
    }
}

void GraphGraph::on_btnAdd_clicked()
{
    QString t = ui->newNodo->text();
    Nodo*n = new Nodo(t);

    if(g->addNodo(n))
    {
        NodoVisual *nuevo = new NodoVisual(n);
        setVisualNode(scene,nuevo);
        nodos->push_back(nuevo);
        fillLists();
    }
}

void GraphGraph::on_btnCreate_clicked()
{
    Nodo* ni = g->search(ui->fromNodoC->currentText());
    Nodo* nf = g->search(ui->toNodoC->currentText());
    int peso = ui->pesoArista->text().toInt();
    if(g->addArista(ni,nf,peso))//mostrar mensaje
        setVisualArista(g,nodos,scene,ni,nf,peso);
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

void GraphGraph::on_btnPrim_clicked()
{
    Nodo*origen = g->search(ui->origenNodo_KrusPri->currentText());
    cout<<">>>Presiono Prim<<<"<<endl;
    Graph *graph = g->Prim(origen);
    cout<<"Total Aristas: "<<graph->aristasND.size()<<endl;
    scene_Prim->clear();
    nodos_prim->clear();
    vector<QString> agregados;

    Nodo*tmp = graph->actual;
    while (tmp) {
        NodoVisual*nuevo = new NodoVisual(tmp);
        setVisualNode(scene_Prim,nuevo);
        nodos_prim->push_back(nuevo);
        agregados.push_back(nuevo->nodo->valor);
        tmp = tmp->adyacente;
    }

    for (int i = 0; i < graph->aristasND.size(); ++i) {
        NodoVisual*inicio = new NodoVisual((graph->aristasND)[i]->inicio);
        NodoVisual*final = new NodoVisual((graph->aristasND)[i]->final);
        int peso = (graph->aristasND)[i]->peso;
        bool addInicio=true,addFinal=true;
//        cout<<"Total Aristas: "<<graph->size()<<endl;
        cout<<"agregando: "<<inicio->nodo->valor.toStdString()<<" Peso: "<<peso<<" Final: "<<final->nodo->valor.toStdString()<<endl;
//        for (int j = 0; j < agregados.size(); ++j) {
//            if(agregados[j]==inicio->nodo->valor)
//                addInicio=false;
//            if(agregados[j]==final->nodo->valor)
//                addFinal=false;
//        }

//        if(addInicio)
//        {
//            setVisualNode(scene_Prim,inicio);
//            nodos_prim->push_back(inicio);
//            agregados.push_back(inicio->nodo->valor);
//        }
//        if(addFinal)
//        {
//            setVisualNode(scene_Prim,final);
//            nodos_prim->push_back(final);
//            agregados.push_back(final->nodo->valor);
//        }
        if(inicio->nodo->valor!="-1")
            setVisualArista(graph,nodos_prim,scene_Prim,inicio->nodo,final->nodo,peso);
        cout<<"Total Nodos agregados: "<<nodos_prim->size()<<endl;
    }
    ui->gView->setScene(scene_Prim);
    cout<<"Total Nodos agregad0s: "<<nodos_prim->size()<<endl;
}

void GraphGraph::on_btnFloyd_clicked()
{
    vector<QString> data = g->Floyd(NULL);
    scene_Floyd->clear();
    for(int i=0;i<data.size();i++)
    {
        QGraphicsTextItem *item = new QGraphicsTextItem();
        item->setPlainText(data[i]);
        item->setPos(0,i*50);
        scene_Floyd->addItem(item);
    }
    ui->gView->setScene(scene_Floyd);
}

void GraphGraph::on_btnKruskal_clicked()
{
    Graph*graph = g->Kruskal(NULL);
    cout<<"Kruskal size: "<<graph->size()<<endl;

    scene_Kruskal->clear();
    nodos_kruskal->clear();

    vector<QString> agregados;

    Nodo*tmp = graph->actual;

    while (tmp) {
        NodoVisual*nuevo = new NodoVisual(tmp);
        setVisualNode(scene_Kruskal,nuevo);
        nodos_kruskal->push_back(nuevo);
        agregados.push_back(nuevo->nodo->valor);
        tmp = tmp->adyacente;
    }

    for (int i = 0; i < graph->aristasND.size(); ++i) {
        NodoVisual*inicio = new NodoVisual((graph->aristasND)[i]->inicio);
        NodoVisual*final = new NodoVisual((graph->aristasND)[i]->final);
        int peso = (graph->aristasND)[i]->peso;

        cout<<"agregando: "<<inicio->nodo->valor.toStdString()<<" Peso: "<<peso<<" Final: "<<final->nodo->valor.toStdString()<<endl;

        if(inicio->nodo->valor!="-1")
            setVisualArista(graph,nodos_kruskal,scene_Kruskal,inicio->nodo,final->nodo,peso);
        cout<<"Total Nodos agregados: "<<nodos_kruskal->size()<<endl;
    }
    ui->gView->setScene(scene_Kruskal);
    cout<<"Total Nodos agregad0s: "<<nodos_kruskal->size()<<endl;
}

void GraphGraph::on_actionGrafo_Original_triggered()
{
    ui->gView->setScene(scene);
}

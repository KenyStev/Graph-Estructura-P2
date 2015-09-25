#include "graph.h"

Graph::Graph(bool d)
{
    actual = NULL;
    dirigido = d;
    Size=0;
}

bool Graph::addNodo(Nodo *nuevo)
{
    if(!search(nuevo->valor))
    {
        nuevo->index=Size;
        if(!actual)
        {
            actual = nuevo;
        }else{
            Nodo * tmp = actual;
            while(tmp->adyacente)
            {
                tmp = tmp->adyacente;
            }
            tmp->adyacente = nuevo;
        }
        Size++;
        return true;
    }
    return false;
}

bool Graph::addArista(Nodo *inicio, Nodo *final, int peso)
{
    if(inicio!=NULL && final!=NULL)
    {
        if(dirigido)
        {
            if(!searchAristaD(inicio,final))
            {
                AristaD *a = (AristaD*)inicio->aristas, *last = a;

                if(!a)
                {
                    inicio->aristas = new AristaD(peso,final);
                    AristaND *aND = new AristaND(peso,inicio,final);
                    aristasND.push_back(aND);
                    return true;
                }else{
                    while(a)
                    {
                        last = a;
                        if(a->final == final)
                            return false;
                        a = (AristaD*)a->adyacente;
                    }
                    AristaD *add = new AristaD(peso,final);
                    last->adyacente = add;
                    AristaND *aND = new AristaND(peso,inicio,final);
                    aristasND.push_back(aND);
                    return true;
                }
            }
        }else{
            if(!searchAristaND(inicio,final))
            {
                AristaND *a = new AristaND(peso,inicio,final);
                aristasND.push_back(a);
                inicio->addArista(final,peso);
                final->addArista(inicio,peso);
                return true;
            }
        }
        cout<<"Arista agregada"<<endl;
    }
    return false;
}

Nodo *Graph::search(QString n)
{
    return search(n,actual);
}

Nodo *Graph::search(QString n, Nodo *Actual)
{
    if(Actual)
    {
        if(Actual->valor==n)
            return Actual;
        return search(n,Actual->adyacente);
    }
    return NULL;
}

vector<QString> Graph::Dijkstra(Nodo *origen)
{
    vector<QString> tabla;
    Queue cola;

    int current, peso, adyacent;
    int V = size();
    cout<<"Size: "<<V<<endl;

    int arr[4][V];
    for( int i = 0 ; i < V ; i++ )
    {
        arr[POS][i] = i;
        arr[PESO][i] = INF;
        arr[CHECKED][i] = false;
        arr[PATH][i] = -1;
    }

    cola.push(origen,0);
    arr[PESO][index(origen)] = 0;

    while(!cola.empty())
    {
        Arista *tmp = cola.pop();
        current = index(tmp->final);

        cout<<"evaluando a: "<<current<<endl;

        //si el nodo fue chequeado lo omite
        if(arr[CHECKED][current])continue;
        arr[CHECKED][current] = true;

        Arista *adyacente = tmp->final->aristas;
        while (adyacente) {
            adyacent = index(adyacente->final);
            peso = adyacente->peso;
            if(!arr[CHECKED][adyacent])
            {
                if( arr[PESO][current] + peso < arr[PESO][adyacent]){
                    arr[PESO][adyacent] = arr[PESO][current] + peso;
                    arr[PATH][adyacent] = current;
                    cola.push(adyacente->final,arr[PESO][adyacent]);//peso);

                    cout<<"Cambio en "<<adyacent<<" Peso: "<<arr[PESO][adyacent]<<" Path: "<<current<<endl;
                }
            }
            adyacente = adyacente->adyacente;
        }
    }

    for (int i = 0; i < 4; ++i) {
        QString text="";
        for (int j = 0; j < V; ++j) {
            text += QString::number(arr[i][j]) + "\t";
        }
        switch (i) {
        case 0:
            text = "Nodo: \t" + text;
            break;
        case 1:
            text = "Peso: \t" + text;
            break;
        case 2:
            text = "Visitado: \t" + text;
            break;
        case 3:
            text = "Path: \t" + text;
            break;
        }
        cout<<text.toStdString()<<endl;
        tabla.push_back(text);
    }

    return tabla;
}

vector<QString> Graph::Floyd(Nodo *origen)
{
    vector<QString> tabla;

    int const DSize=size();
    //int D[DSize][DSize] = {{0,3,5,9999,6},
    //                       {9999,0,4,-1,4},
    //                       {9999,9999,0,9999,2},
    //                       {9999,9999,4,0,12},
    //                       {7,9999,9999,-5,0}};
    int D[DSize][DSize]; /*= {{0,9999,4,9999,9999,9999,9999,9999},
                           {9999,0,9999,9999,3,9999,9999,9999},
                           {9999,9999,0,1,9999,9999,9999,9999},
                           {9999,9999,9999,0,9999,9999,9999,9999},
                           {1,9999,9999,9999,0,2,9999,9999},
                           {9999,2,9999,9999,9999,0,9999,9999},
                           {9999,9999,9999,9999,9999,1,0,9999},
                           {10,9999,0,2,9999,3,1,0}};*/
    int P[DSize][DSize];

    vector<Nodo*> vertices;
    Nodo* tmp = actual;
    while (tmp) {
        vertices.push_back(tmp);
        tmp=tmp->adyacente;
    }

    //fill with infinito
    for (int i = 0; i < DSize; ++i) {
        for (int j = 0; j < DSize; ++j) {
            D[i][j] = INF;
            P[i][j] = -1;
        }
        D[i][i] = 0;
    }

    //fillTabla
    for (int i = 0; i < DSize; ++i) {
        Arista*a = vertices[i]->aristas;
        for (int j = 0; j < DSize; ++j) {

            if (a) {
                D[i][a->final->index] = a->peso;
//                D[a->final->index][j] = a->peso;
                a=a->adyacente;
            }
        }
    }

    //print
    for(int i=0;i<DSize;i++)
    {
        for (int j = 0; j < DSize; ++j) {
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    for(int i=0;i<DSize;i++)
    {
        for (int j = 0; j < DSize; ++j) {
            cout<<P[i][j]<<" ";
        }
        cout<<endl;
    }

    //ejecutar floyd
    for (int k = 0; k < DSize; k++)
    {
        for(int i=0;i < DSize;i++)
        {
            for (int j = 0; j < DSize; j++)
            {
                if((D[i][k] + D[k][j]) < D[i][j])
                {
                    D[i][j] = D[i][k] + D[k][j];
                    P[i][j] = k;
                }
            }
        }
    }

    //print last
    for(int i=0;i<DSize;i++)
    {
        for (int j = 0; j < DSize; ++j) {
            cout<<D[i][j]<<" ";
        }
        cout<<endl;
    }

    cout<<endl<<endl;

    for(int i=0;i<DSize;i++)
    {
        QString text="";

        for (int j = 0; j < DSize; ++j) {
            cout<<D[i][j]<<" ";
            text+=QString::number(D[i][j]) + "\t";
        }
        text+="|\t";
        cout<<endl;

        for (int j = 0; j < DSize; ++j) {
            cout<<P[i][j]<<" ";
            text+=QString::number(P[i][j]) + "\t";
        }
        tabla.push_back(text);
        cout<<endl;
    }

    return tabla;
}

Graph* Graph::Prim(Nodo *origen)
{
    Graph *prim = new Graph(dirigido);

    vector<QString> tabla;
    Queue cola;

    int current, peso, adyacent;
    int V = size();
    cout<<"Size: "<<V<<endl;

    int arr[4][V];
    for( int i = 0 ; i < V ; i++ )
    {
        arr[POS][i] = i;
        arr[PESO][i] = INF;
        arr[CHECKED][i] = false;
        arr[PATH][i] = -1;
    }

    cola.push(origen,0);
    arr[PESO][index(origen)] = 0;

    while(!cola.empty())
    {
        Arista *tmp = cola.pop();
        current = index(tmp->final);

        cout<<"evaluando a: "<<current<<endl;

        //si el nodo fue chequeado lo omite
        if(arr[CHECKED][current])continue;
        arr[CHECKED][current] = true;

        Arista *adyacente = tmp->final->aristas;
        while (adyacente) {
            adyacent = index(adyacente->final);
            peso = adyacente->peso;
            if(!arr[CHECKED][adyacent])
            {
                if( peso < arr[PESO][adyacent]){
                    arr[PESO][adyacent] = peso;
                    arr[PATH][adyacent] = current;
                    cola.push(adyacente->final,arr[PESO][adyacent]);//peso);

                    cout<<"Cambio en "<<adyacent<<" Peso: "<<arr[PESO][adyacent]<<" Path: "<<current<<endl;
                }
            }
            adyacente = adyacente->adyacente;
        }
    }

    cout<<"Prim>>>>>>>>>>>>>>"<<endl;
    for (int i = 0; i < 4; ++i) {
        QString text="";
        for (int j = 0; j < V; ++j) {
//            if(i==0 || i==3)
//                text += getAt(arr[i][j])->valor + "\t";//probando
//            else
                text += QString::number(arr[i][j]) + "\t";
//            cout<<getAt(arr[i][j])->valor.toStdString()<<endl;
        }
        switch (i) {
        case 0:
            text = "Nodo: \t" + text;
            break;
        case 1:
            text = "Peso: \t" + text;
            break;
        case 2:
            text = "Visitado: \t" + text;
            break;
        case 3:
            text = "Path: \t" + text;
            break;
        }
        cout<<text.toStdString()<<endl;
        tabla.push_back(text);
    }

    for (int i = 0; i < V; ++i) {
        Nodo* from,*to;

        to = getAt(arr[POS][i]);
//        cout<<"index to: "<<to->valor.toStdString()<<endl;
        if(!(to->valor=="-1"))
        {
            to = new Nodo(to->valor);//getAt(arr[POS][i])->valor);
            prim->addNodo(to);
//            to->index = getAt(arr[POS][i])->index;
            cout<<"index to: "<<to->valor.toStdString()<<endl;
        }

        if(arr[PATH][i]!=-1)
        {
            from = getAt(arr[PATH][i]);
//            cout<<"index from: "<<from->valor.toStdString()<<endl;
            if(from->valor!="-1")
            {
                from = new Nodo(from->valor);//getAt(arr[PATH][i])->valor);
                prim->addNodo(from);
//                from->index = getAt(arr[PATH][i])->index;
                cout<<"index from: "<<from->valor.toStdString()<<endl;
            }

            prim->addArista(from,to,arr[PESO][i]);
        }
    }
    cout<<"Aristas Prim Size: "<<prim->aristasND.size()<<endl;
    cout<<"Nodos Prim Size: "<<prim->size()<<endl;

    return prim;
}

Graph *Graph::Kruskal(Nodo *origen)
{
    if(!dirigido)
    {
        int conections[size()];
        for (int i = 0; i < size(); ++i) {
            conections[i] = -1;
        }


    }
}

int Graph::size()
{
    return Size;
}

int Graph::index(Nodo * n)
{
    Nodo*tmp = actual;
    int i=0;
    while (tmp) {
        if(tmp==n)
            return i;
        i++;
        tmp = tmp->adyacente;
    }
    return -1;
}

void Graph::falsearNodos()
{
    Nodo* tmp = actual;
    while (tmp) {
        tmp->intree = false;
        tmp = tmp->adyacente;
    }
}

Nodo *Graph::getAt(int index)
{
//    int i=0;
    Nodo* tmp = actual;
    while (tmp) {
        if(tmp->index==index)
            return tmp;
//        i++;
        tmp = tmp->adyacente;
    }
    return new Nodo("-1");
}

//void Graph::Dijkstra(Nodo *inicio)
//{

//}

AristaD *Graph::searchAristaD(Nodo *i, Nodo *f)
{
    Arista*tmp = i->aristas;
    while (tmp) {
        if(tmp->final==f)
            return (AristaD*)tmp;
        tmp = ((AristaD*)tmp)->adyacente;
    }
    return NULL;
}

AristaND *Graph::searchAristaND(Nodo *inicio, Nodo *fin)
{
    for(int i=0;i<aristasND.size();i++)
    {
        if(aristasND[i]->inicio==inicio && aristasND[i]->final==fin)
            return aristasND[i];
    }
    return NULL;
}

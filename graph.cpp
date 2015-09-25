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

vector<string> Graph::Floyd(Nodo *)
{

}

Graph *Graph::Prim(Nodo *)
{

}

Graph *Graph::Kruskal(Nodo *)
{

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

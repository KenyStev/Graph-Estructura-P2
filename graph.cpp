#include "graph.h"

Graph::Graph(bool d)
{
    actual = NULL;
    dirigido = d;
}

void Graph::addNodo(Nodo *nuevo)
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
}

void Graph::addArista(Nodo *inicio, Nodo *final, int peso)
{
    if(inicio!=NULL && final!=NULL)
    {
        Arista *a = inicio->aristas, *last = a;

        if(!a)
        {
            inicio->aristas = new Arista(peso,final);
        }else{
            while(a)
            {
                last = a;
                if(a->final == final)
                    return;
                a = a->adyacente;
            }
            Arista *add = new Arista(peso,final);
            last->adyacente = add;
        }
        cout<<"Arista agregada"<<endl;
    }
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

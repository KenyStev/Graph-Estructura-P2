#include "queue.h"

Queue::Queue()
{
    root = NULL;
    end = NULL;
}

Queue::~Queue()
{

}

void Queue::push(QString v)
{
//    if(!root)
//    {
//        root = new Nodo(v);
//        end = root;
//    }else{
//        end->adyacente = new Nodo(v);
////        end->adyacente->before = end;
//        end = end->adyacente;
//    }
}

void Queue::push(Nodo* v,int distancia)
{
//    cout<<"distancia: "<<distancia<<endl;
    if(!root)
    {
        root = new Arista(distancia,v);
        root->adyacente = NULL;
        end = root;
        return;
    }else if(root->peso > distancia)
    {
        Arista*tmp = root;
        root = new Arista(distancia,v);
        root->adyacente = tmp;
        return;
    }else if(end->peso < distancia)
    {
        end->adyacente = new Arista(distancia,v);
        end = end->adyacente;
        end->adyacente = NULL;
        return;
    }

    Arista*tmp = root;
    while (tmp->adyacente && tmp->adyacente->peso < distancia) {
        tmp = tmp->adyacente;
    }
    Arista *t = new Arista(distancia,v);
    t->adyacente = tmp->adyacente;
    tmp->adyacente = t;
}

void Queue::push(Arista *nueva, int distancia)
{
    if(!root)
    {
        root = nueva;
        root->adyacente = NULL;
        end = root;
        return;
    }else if(root->peso > distancia)
    {
        Arista*tmp = root;
        root = nueva;
        root->adyacente = tmp;
        return;
    }else if(end->peso < distancia)
    {
        end->adyacente = nueva;
        end = end->adyacente;
        end->adyacente = NULL;
        return;
    }

    Arista*tmp = root;
    while (tmp->adyacente && tmp->adyacente->peso < distancia) {
        tmp = tmp->adyacente;
    }
    Arista *t = nueva;
    t->adyacente = tmp->adyacente;
    tmp->adyacente = t;
}

Arista *Queue::pop()
{
    if(!root)
        return NULL;
    Arista *tmp = root;
    root = tmp->adyacente;
    return tmp;
}

Arista *Queue::first()
{
    return root;
}

void Queue::clear()
{
    if(root)
    {
        delete pop();
        clear();
    }
}

void Queue::clean()
{
    if(root)
    {
        delete pop();
        clean();
    }
}

bool Queue::empty()
{
    return !root;
}

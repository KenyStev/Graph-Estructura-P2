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
    if(!root)
    {
        root = new Nodo(v);
        end = root;
    }else{
        end->adyacente = new Nodo(v);
//        end->adyacente->before = end;
        end = end->adyacente;
    }
}

void Queue::push(Nodo* v)
{
    if(!root)
    {
        root = v;
        end = root;
    }else{
        end->adyacente = v;
        end = end->adyacente;
    }
}

Nodo *Queue::pop()
{
    if(!root)
        return NULL;
    Nodo *tmp = root;
    root = tmp->adyacente;
    return tmp;
}

Nodo *Queue::first()
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

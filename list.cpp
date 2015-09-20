#include "list.h"

List::List()
{
    root = NULL;
    end = NULL;
}

List::~List()
{
    delete root;
    delete end;
}

void List::add(QString v)
{
    if(!root)
    {
        root = new Nodo(v);
        end = root;
    }else{
        end->adyacente = new Nodo(v);
        end = end->adyacente;
    }
}

void List::add(Nodo *v)
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
//luis.isaula94@gmail.com
bool List::insert(QString vIndex,QString v)
{
    if(!root)
    {
        add(v);
        return false;
    }else{
        Nodo *tmp = search(vIndex);
        if(tmp)
        {
            Nodo *newNodo = new Nodo(v);
            if(root->valor==tmp->valor)
            {
                newNodo->adyacente = root;
                root = newNodo;
                return true;
            }
            Nodo *before = searchBefore(vIndex);
            newNodo->adyacente = tmp;
            before->adyacente = newNodo;
            return true;
        }
    }
}

Nodo* List::search(QString v)
{
    return search(v,root);
}

Nodo* List::search(QString v, Nodo* r)
{
    if(r)
    {
        if(r->valor==v)
            return r;
        return search(v,r->adyacente);
    }
    return NULL;
}

Nodo* List::searchBefore(QString v)
{
    Nodo *tmp = root;
    while (tmp->adyacente) {
        if(tmp->adyacente->valor==v)
            return tmp;
    }
    return NULL;
}

void List::dispose(QString v)
{
    if(root)
    {
        if(root->valor==v)
        {
            Nodo *tmp = root;
            root = root->adyacente;
            //delete tmp;
        }else{
            Nodo *tmp = searchBefore(v);
            if(tmp)
            {
                Nodo *t = tmp->adyacente;
                tmp->adyacente = t->adyacente;
                //delete t;
            }
        }
    }
}

void List::clear()
{
    if(root)
    {
        root = NULL;
//        Nodo *t = root;
//        root = t->adyacente;
//        delete t;
//        clear();
    }
}

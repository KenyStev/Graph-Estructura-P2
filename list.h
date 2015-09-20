#ifndef LIST_H
#define LIST_H
#include <QString>
#include "nodo.h"

class List
{

public:
    explicit List();
    ~List();
    void add(QString);
    void add(Nodo*);
    bool insert(QString,QString);
    Nodo* search(QString);
    Nodo* search(QString,Nodo*);
    Nodo* searchBefore(QString);
    void dispose(QString);
    void clear();

private:
    Nodo *root, *end;
};

#endif // LIST_H

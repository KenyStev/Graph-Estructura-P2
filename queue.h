#ifndef QUEUE_H
#define QUEUE_H
#include "nodo.h"

class Queue
{

public:
    Queue();
    ~Queue();

    void push(QString);
    void push(Nodo*);
    Nodo* pop();
    Nodo* first();
    void clear();
    void clean();

private:
    Nodo* root;
    Nodo* end;


};

#endif // QUEUE_H

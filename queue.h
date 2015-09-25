#ifndef QUEUE_H
#define QUEUE_H
#include "nodo.h"

class Queue
{

public:
    Queue();
    ~Queue();

    void push(QString);
    void push(Nodo*,int);
    Arista* pop();
    Arista* first();
    void clear();
    void clean();
    bool empty();

private:
    Arista* root;
    Arista* end;


};

#endif // QUEUE_H

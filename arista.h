#ifndef ARISTA
#define ARISTA

class Nodo;

class Arista
{
public:
    Nodo *final;
    Arista *adyacente;
    int peso;

    Arista(int p,Nodo* f)
    {
        peso = p;
        final = f;
        adyacente = NULL;
    }
};

#endif // ARISTA_H


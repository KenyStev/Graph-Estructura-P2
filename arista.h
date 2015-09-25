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
        adyacente=NULL;
        peso = p;
        final = f;
    }
};

class AristaD : public Arista
{
public:
//    Arista *adyacente;
    AristaD(int p,Nodo*n) : Arista(p,n)
    {
//        adyacente=NULL;
    }
};

class AristaND : public Arista
{
public:
    Nodo *inicio;
    bool iterado;
    AristaND(int p,Nodo*i,Nodo*f) : Arista(p,f)
    {
        inicio=i;
        iterado=false;
    }
};

#endif // ARISTA_H


#include <cstdlib>	
#include <iostream>

template <typename tipoElemento>
class Pila
{public:
    Pila (int max);
   ~Pila();
    void push(tipoElemento V);
    tipoElemento pop();
    int vacia();
     private:
    struct nodo
       {tipoElemento clave; struct nodo *siguiente;};
   struct  nodo *cabeza, *z;
 };

template <typename tipoElemento>
Pila<tipoElemento>::Pila(int max)
{ cabeza = new nodo;  z=new nodo;
  cabeza->siguiente=z; z->siguiente =z;
}


template <typename tipoElemento>
Pila<tipoElemento>::~Pila()
{struct nodo *t=cabeza;
 while (t!=z)
       {cabeza=t; t=t->siguiente;  delete cabeza;}
       delete z;
}

template <typename tipoElemento>
void Pila<tipoElemento>:: push (tipoElemento v)
{struct nodo *t=new nodo;
 t->clave = v;  t->siguiente=cabeza->siguiente;
cabeza->siguiente=t;
}

template <typename tipoElemento>
tipoElemento Pila<tipoElemento>::pop()
{tipoElemento x;
 struct nodo *t = cabeza->siguiente;
cabeza->siguiente = t->siguiente; x=t->clave;
delete t; return x;
}

template <typename tipoElemento>
int Pila<tipoElemento>::vacia()
{return cabeza->siguiente == z;}

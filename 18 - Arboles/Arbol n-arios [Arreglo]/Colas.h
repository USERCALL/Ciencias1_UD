#ifndef COLAS_H     
#define COLAS_H 
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
struct Nodo
{ Nodo <T> *sig;
  T info;       
};

template <class T>
class Colas{Nodo <T> *cab;
            int tam;
     public: Colas(){cab = NULL;
                     tam =0;}
             bool cola_vacia();
             int tamano_cola();
             T get();
             void put(T infoNueva);
};

template <class T>
void Colas<T>::put(T infoNueva)
{ Nodo <T> *nuevo;
  nuevo = new Nodo <T>;
  nuevo->info = infoNueva;
  nuevo->sig = NULL;
  if(tam == 0)
    {cab = nuevo;}
  else
    {Nodo <T> *aux;
     aux = cab;
     while(aux->sig != NULL)
        {aux = aux->sig;}
     aux->sig = nuevo;
    }
  tam++;
}

template <class T>
T Colas<T>::get()
{ 
   Nodo <T> *aux;
   T info;
   aux = cab;
   cab = aux->sig;
   info = aux->info;
   delete aux;
   return info;
}

template <class T>
bool Colas<T>::cola_vacia()
{     if(tam == 0)
        return true;
     else
        return false;
}

template <class T>
int Colas<T>::tamano_cola()
{ return tam;}

#endif


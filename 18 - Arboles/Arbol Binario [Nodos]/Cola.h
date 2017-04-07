#ifndef COLA_H     
#define COLA_H 
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
struct Nodo
{ Nodo <T> *sig;
  Nodo <T> *ant;
  T info;       
};

template <class T>
class Cola{Nodo <T> *cab, *z;
            int tam;
     public: Cola(){cab = NULL; z = NULL;
                     tam =0;}
             bool cola_vacia();
             int tamano_cola();
             T dequeve(string lado);
             void enqueve(T infoNueva,string lado);
};

template <class T>
void Cola<T>::enqueve(T infoNueva , string lado)
{ 
  Nodo <T> *nuevo;
  nuevo->info = infoNueva;
  if (lado == "I"){
     nuevo->sig = NULL;
     nuevo->ant = z;
     z->sig = nuevo;
     z = nuevo;      
  }else if (lado == "D"){
     nuevo->ant = NULL;
     nuevo->sig = cab;
     cab->ant = nuevo;
     cab = nuevo;
  }      
  tam++;     
}

template <class T>
T Cola<T>::dequeve(string lado)
{ 

  Nodo <T> *aux; 
  T info;                        
  if (lado == "I"){
     aux = cab;
     cab = cab->sig;
     cab->ant = NULL;
     info = aux->info;
  }else if (lado == "D"){
     aux = z;
     z = z->ant;
     z->sig = NULL;
     info = aux->info;
  }      
  tam--;
  delete aux;
  return info;
}

template <class T>
bool Cola<T>::cola_vacia()
{     if(tam == 0)
        return true;
     else
        return false;
}

template <class T>
int Cola<T>::tamano_cola()
{ return tam;}

#endif


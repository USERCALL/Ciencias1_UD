/*******************************************************************************
Algoritmo de colas genericas sencillas pg 32 sedgewick Robert Algoritmos en c++
*******************************************************************************/

//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058

/*******************************************************************************
 	bool cola_vacia();
    int tamano_cola();
    T atender();
    void enColar(T infoNueva);};
*******************************************************************************/


#ifndef COLA_H     
#define COLA_H 
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
struct Nodo{ Nodo <T> *sig; T info;};

template <class T>
class Colas{
	Nodo <T> *cab;
    int tam;
    
	public: Cola();
            bool cola_vacia();
            int tamano_cola();
            T atender();
            void enColar(T infoNueva);};
        
template <class T>
Cola<T>::Colas(){
	cab = NULL;
    tam =0;}


template <class T>
void Cola<T>::enColar(T infoNueva){
	Nodo <T> *nuevo;
	nuevo = new Nodo <T>;
	nuevo->info = infoNueva;
  	nuevo->sig = NULL;
  	if(tam == 0){
	  	cab = nuevo;
	}else{
   		Nodo <T> *aux;
    	aux = cab;
    	while(aux->sig != NULL){
			aux = aux->sig;}
    	aux->sig = nuevo;}
  		tam++;}


template <class T>
T Cola<T>::atender(){ 
	Nodo <T> *aux;
    T info;
    aux = cab;
    cab = aux->sig;
    info = aux->info;
    delete aux;
    return info;}


template <class T>
bool Cola<T>::cola_vacia(){
    if(tam == 0){
    	return true;
    }else{
		return false;}}


template <class T>
int Cola<T>::tamano_cola(){ 
	return tam;}

#endif


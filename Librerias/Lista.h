#ifndef LISTA_H     
#define LISTA_H  
#include <cstdlib>
#include <iostream>

using namespace std;

template <class T>
struct Nodo{ 
	Nodo <T> *ant;
	Nodo <T> *sig;
  	T info; //Esta es la informacion de la lista  
};

template <class T>
class Lista{
	Nodo <T> *cab;
    int tam;
    public: Lista(){cab = NULL;
                     tam =0;}
            void imprimir();
            void circular();
            bool lista_vacia();
            int tamano_lista();
            T obtenerDato(int pos);
            bool eliminar(int pos);
            void insertar_final(T infoNueva);
            void insertar_pos(T infoNueva, int pos);
            void insertar_inicio(T infoNueva);};



template <class T>
void Lista<T>::insertar_pos(T infoNueva, int pos){
	if(pos > tam){
    	insertar_final(infoNueva);
  	}else{
		if (pos==1){
            insertar_inicio(infoNueva);
       	}else{ 
			Nodo <T> *nuevo, *aux;
            nuevo = new Nodo <T>;
            nuevo->info = infoNueva;
            aux = cab;
            int p = 1;
            while(p<pos-1 && aux != NULL){
				aux = aux->sig;
                p++;}
            nuevo->ant=aux;
            (aux->sig)->ant=nuevo;
            nuevo->sig=aux->sig;
            aux->sig=nuevo;
            tam++;}}}


template <class T>
void Lista<T>::insertar_final(T infoNueva){
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
     	nuevo->ant = aux;
     	aux->sig = nuevo;}
  	tam++;}


template <class T>
void Lista<T>::insertar_inicio(T infoNueva){
	Nodo <T> *nuevo , *aux;
	nuevo = new Nodo <T>;
    nuevo->info = infoNueva;
	nuevo->sig = cab;
	nuevo->ant = NULL;
	cab = nuevo;
	tam++;}


template <class T>
T Lista<T>::obtenerDato(int pos){
	Nodo <T> *aux;
    aux = cab;
    int p = 1;
    while(p<pos && aux != NULL){
	    aux = aux->sig;
        p++;}
    if(aux!=NULL){
         return aux->info;}
    return 0;}


template <class T>
bool Lista<T>::eliminar(int pos){
	if(tam >= pos){
		Nodo <T> *temp;
        temp = cab;
        if(pos == 1){
			cab = temp->sig;
          	delete temp;
        }else{
			for(int i=1;i<=pos-1;i++){
				temp = temp->sig;}
          	Nodo <T> *aux ;          
          	if (temp->sig!=NULL){
            	Nodo <T> *aux2 ; 
                aux2 = temp->ant;
              	aux = temp->sig;
              	aux2->sig = temp->sig;
              	aux->ant = temp->ant;
          	}else{
              	aux = temp->ant;
              	aux->sig = NULL;}
       	delete temp;}
    tam--;
    return true;
	}else{
		return false;}}


template <class T>
bool Lista<T>::lista_vacia(){
	if(tam == 0){
		return true;
	}else{
		return false;}}

template <class T>
void Lista<T>::circular(){
    Nodo <T> *aux , *aux2;
    aux = aux2 = cab;
    while(aux2 != NULL){
		aux2 = aux2->sig;}
    aux2->sig = aux;
    aux->ant = aux2;}


template <class T>
int Lista<T>::tamano_lista(){ return tam;}


template <class T>
void Lista<T>::imprimir(){
	if(lista_vacia()){
		cout<<"La Lista no tiene Informacion"<<endl;
	}else{
        cout<<"La informacion de la Lista es:"<<endl;
        Nodo <T> *aux;
        aux = cab;
        int pos = 1;
        while(aux != NULL){
            cout<<"Info "<<pos<<": "<<aux->info<<endl;
            aux = aux->sig;
            pos++;}}}
#endif


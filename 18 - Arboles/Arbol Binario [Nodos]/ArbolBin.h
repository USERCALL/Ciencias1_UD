#include "cola.h"
#include <iostream>

struct nodo {
	nodo *izq;
	nodo *der;
	int info; 
};

class ArbolBinarioOrdenado{
	nodo *raiz;
	Cola<int> *lInorden;
	Cola<int> *lPreOrden;
	Cola<int> *lPostOrden;
	
	public :
		
		ArbolBinarioOrdenado(){
			raiz = NULL; 
			
		}
		void inicio(int t);
        ////////
        
		void insertar (int info){
			//alisto nodo
			nodo *nuevo; 
			nuevo->info = info; 
			nuevo->der = NULL;
			nuevo->izq = NULL; 
			
			
			if(raiz->info == NULL){
				raiz = nuevo;
			}else{
				nodo *aux ; 
				aux = raiz;
				
				while(aux->izq!=NULL && aux->der!=NULL){
					// decidonedo camino a escoger
					if(aux->info < info){
						aux = aux->izq;
					}else{
						aux = aux->der;
					}	
				}
				
				//proceso de insercion
				if(aux->info < info){
					aux->izq = nuevo;
				}else{
					aux->der = nuevo; 
				}
			}	
		}
		
        int buscar (int info);
        void eliminar (int info);
        void inOrden();
        void preOrden();
        void porNivel();
};

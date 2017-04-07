/*******************************************************************************
Algoritmo de pilas por punteros con tempplates tomado de Sedgewick Algoritmos 
en c++ pag 32
*******************************************************************************/

//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058


/*******************************************************************************
	Pila (int max);
   	~Pila();
   	void meter(T key);
   	T sacar();
    int vacia();
*******************************************************************************/

#include <cstdlib>	
#include <iostream>

template <class T>
class Pila{
	
	public:
    	Pila (int max);
   		~Pila();
   		void meter(T key);
   		T sacar();
    	int vacia();
    
	private:
    	struct nodo{T clave; struct nodo *siguiente;};
   		struct  nodo *cabeza, *z;};



template <class T>
Pila<T>::Pila(int max){
	cabeza = new nodo;
	z=new nodo;
	cabeza->siguiente = z;
	z->siguiente = z;}


template <class T>
Pila<T>::~Pila(){
	struct nodo *t = cabeza;
 	while (t!=z){	
		cabeza = t;
		t = t->siguiente;
		delete cabeza;}
    delete z;}


template <class T>
void Pila<T>::meter(T key){
	struct nodo *t = new nodo;
 	t->clave = key;
	t->siguiente = cabeza->siguiente;
	cabeza->siguiente = t;}


template <class T>
T Pila<T>::sacar(){
	T retorno;
 	struct nodo *t = cabeza->siguiente;
	cabeza->siguiente = t->siguiente;
 	retorno = t->clave;
	delete t;
	return retorno;}


template <class T>
int Pila<T>::vacia(){
	return cabeza->siguiente == z;}

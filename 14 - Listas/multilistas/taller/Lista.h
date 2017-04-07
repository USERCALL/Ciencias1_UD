/*******************************************************************************
Listas enlazadas  Algortimo Sedgewick Robert -> Algoritmos en c++
con programacion generica
********************************************************************************/

//Diego Hernandez -> 20141020271

#ifndef LISTA_H
#define LISTA_H
#include <iostream>
using namespace std;

template <class T>
struct nodo{
	T info;	
	nodo<T> *sig=NULL,*ant=NULL;};


template <class T>
class Lista{
	private:
		nodo<T> *cab;
		nodo<T> *z; // * a ultimo elemento, optimiza para saber donde imsertar
		int tam;
		
	public:
		Lista();
	
		void insertarInicio(T elemento);
		void insertarFinal(T elemento);
		void insertar_pos(int pos,T infoNueva);
		void insertarPos(T elemento,int pos);
		bool borrarElemento(int pos);
		bool modificarElemento(int pos, T elemento);
		T buscarElemento(int pos);
	
	nodo<T> getZ();
	void imprimirLista();
	int listaTam();};

template <class T>	
Lista<T>::Lista(){		
	cab=new nodo<T>;
	z=new nodo<T>;
	cab->sig=z;	
	z->sig=cab;	
	cab->ant=z;
	z->ant=cab;	
	tam=0;}
	
template <class T>
nodo<T> *ubicarUltimo(nodo<T> *cabeza,nodo<T> *z){
	nodo<T> *aux=cabeza;	
	while(aux->sig!=z){			
		aux=aux->sig;}
	
	return aux;}


template <class T>
void Lista<T>::insertarFinal(T elemento){
	nodo<T> *nuevo=new nodo<T>;	
	nuevo->info=elemento;
	nodo<T> *ultimo=ubicarUltimo(cab,z);	
	ultimo->sig=nuevo;	
	nuevo->ant=ultimo;
	nuevo->sig=z;
	z->ant=nuevo;
	tam++;}


template <class T>
void Lista<T>::insertarInicio(T elemento){
	nodo<T> *nuevo=new nodo<T>;	
	nuevo->info=elemento;
	nodo<T> *primero=cab->sig;
	primero->ant=nuevo;
	nuevo->sig=primero;
	cab->sig=nuevo;
	nuevo->ant=cab;
	tam++;}


template <class T>
void Lista<T>::insertar_pos(int pos,T infoNueva){
	if(pos > tam){
    	insertarFinal(infoNueva);
	}else{
		if (pos==1){
	    	insertarInicio(infoNueva);}
    }else{
	    if((pos>1)&&(pos<=tam)){ 
			nodo <T> *nuevo, *aux;
	        nuevo = new nodo <T>;
	        nuevo->info = infoNueva;
	        aux = cab;
	        int p = 0;
	        while(p<pos-1 && aux != z){
				aux = aux->sig;
	            p++;}
	        nuevo->sig=aux->sig;
	        aux->sig=nuevo;
	        nuevo->ant=aux;
	        nuevo->sig->ant=nuevo;
	        tam++;}}}


template <class T>
bool Lista<T>::borrarElemento(int pos){
	if((pos<=tam)&&(pos>0)){
		int contador=0;
		nodo<T> *aux=cab;
		while(contador<pos){
			aux=aux->sig;
			contador++;}
		if(aux->sig!=NULL){
		aux->sig->ant=aux->ant;}
		aux->ant->sig=aux->sig;
		tam--;
		return true;}}

template <class T>
bool Lista<T>::modificarElemento(int pos, T elemento){
	if((pos<=tam)&&(pos>0)){
		nodo<T> *nuevo=new nodo<T>;
		nuevo->info=elemento;
		int contador=0;
		nodo<T> *aux=cab;
		while(contador<pos){
			aux=aux->sig;
			contador++;}
		aux->ant->sig=nuevo;
		aux->sig->ant=nuevo;
		nuevo->ant=aux->ant;
		nuevo->sig=aux->sig;
		return true;}}


template <class T>
T Lista<T>::buscarElemento(int pos){
	if((pos<=tam)&&(pos>0)){
		nodo <T> *aux=cab;
		int contador=0;
		while(contador<pos){
			aux=aux->sig;
			contador++;}
		return aux->info;}}

template <class T>
void Lista<T>::imprimirLista(){
	for(int i=1;i<=tam;i++){
		cout<<(i)<<" - "<<buscarElemento(i)<<endl;}
	nodo<T> *aux=cab;
	for(int i=0;i<tam;i++){
		aux=aux->sig;}}

template <class T>
int Lista<T>::listaTam(){
	return tam;}
	
	
template <class T>
nodo<T> Lista<T>::getZ(){
	return z;}

#endif    

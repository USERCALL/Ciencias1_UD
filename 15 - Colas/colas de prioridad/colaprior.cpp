#include <iostream>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
template <class T>


struct Nodo {
	
	Nodo <T> *izq,*der,*padre;
	T info; 
};

template <class T>

class cola_prior{
	Nodo<T> *raiz;
	public: 
	
		cola_prior(){
			raiz=NULL;
		}
	
	void insertar(T info, int prior){
		if(raiz==NULL){
			raiz.info= info;
			raiz.der=NULL;
			raiz.izq=NULL;
			raiz.padre=raiz;
			int prior=1;
		}
		else {
			
		}
	};
	Nodo<T> *llenar_Nodo(T info, int prior);
	T Atender();
};




int main(int argc, char** argv) {
	
	return 0;
}

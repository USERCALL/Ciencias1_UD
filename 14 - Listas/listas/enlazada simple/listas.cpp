#include <iostream>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std; 

template <class T>

struct Nodo {
	
	Nodo <T> *sig;
	
	T info; 
};

template <class T>

class lista {
	Nodo <T> *cab; 
	int tam;
	
	public:
		lista() {
		cab=NULL;
		tam=0;
		}
		
		
		void insertar_elemento(T elemento){
			
			Nodo <T> *nuevo;
  			nuevo = new Nodo <T>;
  			nuevo->info = elemento;
  			nuevo->sig = NULL;
  		
		  		if(tam == 0){
	  				cab = nuevo;
				}
  				else{
	  				Nodo <T> *aux;
     				aux = cab;
     				
					 while(aux->sig != NULL){
		 				aux = aux->sig;
						}
					 	
     			aux->sig = nuevo;
    		}
  			tam++;
		}
		
		
		bool lista_vacia(){
		if(tam == 0)
			return true;
    	else
			return false;
		}		
		
	
		void imprimir(){
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
            			pos++;
        			}
			}
		}
		
		T buscar_elemento(int posicion){
			if(tam==0){
				cout<<"la lista no tiene informacion, por tanto no tiene elementos a buscar"<<endl;
			}
			else{
				if(tam<posicion){
					cout<<"la lista es de tamaño menor"<<endl;
				}
				else{
					cout<<"buscando elemento en la posicion: "<<posicion<<endl;
					Nodo <T> *aux;
        		    aux = cab;
					int pos=1;
					while(pos != posicion){
            			aux = aux->sig;
            			pos++;
        			}
					cout<<"la posicion "<<posicion<<" tiene el elemento: "<<aux->info<<endl;
				}
			}
		
		}

		bool borrar_elemento(int pos){
			
			if(tam >= pos){
				Nodo <T> *temp;
       			temp = cab;
       		if(pos == 1){
				cab = temp->sig;
          		delete temp;
        	}
       			else{
					for(int i=1;i<pos-1;i++){
						temp = temp->sig;
					}          
          			Nodo <T> *aux;
          			aux = temp->sig;
          			temp->sig = aux->sig;
          			delete aux;
				}
        	tam--;
        		return true;          
			}else
     			return false;
		}
		
		bool modificar_elemento(int pos, T elemento){
			
			if(pos==1){
				cab->info=elemento;
			}
			else{
				Nodo  <T> *aux;
				aux=cab;
				int contador=1;
				
				while(contador!=pos){
					aux=aux->sig;
					contador++;
				}
				aux->info=elemento;
			}
			
		}
			
	
};


int main(int argc, char** argv) {
	
	lista<int> milista; 
	milista.insertar_elemento(2);
	milista.insertar_elemento(3);
	milista.insertar_elemento(4);
	milista.insertar_elemento(5);
	milista.imprimir();
	milista.buscar_elemento(2);
	milista.borrar_elemento(2);
	milista.imprimir();
	milista.modificar_elemento(2,8);
	milista.imprimir();
	return 0;
}

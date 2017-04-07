/******************************************************************************
Libreria para arboles binacrios ccon arreglos
******************************************************************************/

//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058
//Ciencias Computacion I  (2017-04-17)




#include <cstdlib> 
#include <iostream> 
#include "Pila.h"
#include "Colas.h"

using namespace std;

struct Nod {
    int info, izq, der;
};

class Arbol {
    int tamanio;
   	Pila<int> Rec;
    Colas<int> Reco;
    
    public:
		int tamanio; 
		Arbol() {}
			int num_nodos = 6; // Declara cuantos nodos va a tener el arreglo
			tamanio = num_nodos+1; // Agrega uno que es el espacio inicial
    		Nod arbol[tamanio];
    		Arbol[0].izq = 0; //Poscion de la raiz
			Arbol[0].der = 1; //poscion de sig vacia principal
			
    		for (int i = 1; i < num_nodos; i++) {//llenando donde esta la sig vacia por casilla
        		arbol[i].der = i + 1;
   			}
   			
    	arbol[tamanio].der = 0; //poscion por defecto
		}
		
	 
	    void insertar(int info);
	    int buscar(int info);
	    void eliminar(int info);
	    void inorden();
	    void preorden();
	    void pornivel();
};


void Arbol::insertar(int info) {
    
	int aux;// alamcena sig vacia 
	int aux2; //almacena raiz temporal
	int raiz = arbol[0].izq;
    
    if ( raiz == 0) { // si no se ha inciado
        arbol[0].izq = 1;
        arbol[0].der = arbol[1].der; // reasigno sig vacia principal
        arbol[1].info = info;
        arbol[1].izq = 0; // no tiene hijos 
        arbol[1].der = 0; // no tiene hijos
    } else {
    	
        aux2 =  raiz; // cambio al sig Nodo
        aux = arbol[0].der; // lleva la sig pos vacia
        
        if (aux != 0) { /*Compruba que no se halla llegado al final pos 
							de contro = sig vacia = 0  				*/
        	
            arbol[0].der = arbol[aux].der; // reasigna la sig pos Vacia 
            
			arbol[aux].info = info;
            arbol[aux].izq = 0;
            arbol[aux].der = 0;
            
			while (raiz != 0) { // navegando el bosque
				if (arbol[raiz].info < arbol[aux].info) { /* la informacion ->
				 				padre sea menor o igual al dato a insertar   */
                    aux2 = raiz;
                    raiz = arbol[raiz].der;
                } else {
                    aux2 = raiz;
                    raiz = arbol[raiz].izq;
                }
            }
            
			if (arbol[aux2].info > arbol[aux].info) {
                arbol[aux2].izq = aux;
            } else {
                arbol[aux2].der = aux;
            }
        } else {
            cout << "No se pueden agregar mas elementos" << endl;
        }
    }
}

int Arbol::buscar(int info) {
    int pos;
    pos = arbol[0].izq;
    while (arbol[pos].info != info) {
        if (arbol[pos].info > info) {
            pos = arbol[pos].izq;
        } else {
            pos = arbol[pos].der;
        }
    }
    if (pos == 0) {
        cout << "No se encontro " << info << endl;
        return 0;
    } else {
        return pos;
    }
}

void Arbol::eliminar(int info) {
    int raiz, pos, hoja, padre;
    raiz = arbol[0].izq;
    pos = buscar(info);
    while (arbol[raiz].der != pos && arbol[raiz].izq != pos) {
        if (arbol[raiz].info > info) {
            raiz = arbol[raiz].izq;
        } else {
            raiz = arbol[raiz].der;
        }
    }
    if (pos != 0) {
        if (arbol[pos].izq == 0 && arbol[pos].der == 0) {
            if (arbol[0].izq == pos) {} else {
                if (arbol[raiz].der == pos) {
                    arbol[raiz].der = 0;
                } else {
                    arbol[raiz].izq = 0;
                }
            }

        }
        if (arbol[pos].izq != 0 && arbol[pos].der == 0) {
            hoja = arbol[pos].izq;
            if (arbol[raiz].izq == pos) {
                arbol[raiz].izq = hoja;
            } else {
                arbol[raiz].der = hoja;
            }
            if (arbol[0].izq == pos) {
                arbol[0].izq = hoja;
            }
        }
        if (arbol[pos].izq == 0 && arbol[pos].der != 0) {
            hoja = arbol[pos].der;
            if (arbol[raiz].izq == pos) {
                arbol[raiz].izq = hoja;
            } else {
                arbol[raiz].der = hoja;
            }
            if (arbol[0].izq == pos) {
                arbol[0].izq = hoja;
            }
        }
        if (arbol[pos].izq != 0 && arbol[pos].der != 0) {
            padre = pos;
            hoja = arbol[pos].der;
            while (arbol[hoja].izq != 0) {
                padre = hoja;
                hoja = arbol[hoja].izq;
            }
            if (arbol[padre].izq == hoja) {
                arbol[padre].izq = 0;
                if (arbol[hoja].der != 0) {
                    arbol[padre].izq = arbol[hoja].der;
                }
            } else {
                arbol[padre].der = 0;
            }
            arbol[hoja].izq = arbol[pos].izq;
            arbol[hoja].der = arbol[pos].der;
            if (arbol[raiz].izq == pos) {
                arbol[raiz].izq = hoja;
            } else {
                arbol[raiz].der = hoja;
            }
            if (arbol[0].izq == pos) {
                arbol[0].izq = hoja;
            }
        }
        arbol[pos].info = 0;
        arbol[pos].izq = 0;
        arbol[pos].der = arbol[0].der;
        arbol[0].der = pos;
    }
}

void Arbol::inorden() {
    int recorrido, final;
    recorrido = arbol[0].izq;
    final = arbol[0].izq;
    while (arbol[final].der != 0) {
        final = arbol[final].der;
    }
    while (recorrido != 0) {
        if (arbol[recorrido].izq != 0) {
            Rec.push(recorrido);
            recorrido = arbol[recorrido].izq;
        } else {
            cout << arbol[recorrido].info << " ";
            if (arbol[recorrido].der != 0) {
                recorrido = arbol[recorrido].der;
            } else {
                recorrido = Rec.pop();
                cout << arbol[recorrido].info << " ";
                if (arbol[recorrido].der != 0) {
                    recorrido = arbol[recorrido].der;
                } else {
                    recorrido = Rec.pop();
                    cout << arbol[recorrido].info << " ";
                    recorrido = arbol[recorrido].der;
                }
            }
        }
        if (recorrido == final) {
            cout << arbol[recorrido].info << endl;
            recorrido = 0;
        }
    }
}

void Arbol::preorden() {
    int recorrido, final;
    recorrido = arbol[0].izq;
    final = arbol[0].izq;
    while (arbol[final].der != 0) {
        final = arbol[final].der;
    }
    while (recorrido != 0) {
        if (arbol[recorrido].izq != 0) {
            cout << arbol[recorrido].info << " ";
            Rec.push(recorrido);
            recorrido = arbol[recorrido].izq;
        } else {
            cout << arbol[recorrido].info << " ";
            if (arbol[recorrido].der != 0) {
                cout << arbol[arbol[recorrido].der].info << " ";
            }
            recorrido = Rec.pop();
            while (arbol[recorrido].der == 0) {
                recorrido = Rec.pop();
            }
            recorrido = arbol[recorrido].der;
        }
        if (recorrido == final) {
            cout << arbol[recorrido].info << endl;
            recorrido = 0;
        }
    }
}

void Arbol::pornivel() {
    int recorrido, final;
    recorrido = arbol[0].izq;
    final = arbol[0].izq;
    while (arbol[final].der != 0) {
        final = arbol[final].der;
    }
    while (recorrido != 0) {
        cout << arbol[recorrido].info << " ";
        if (arbol[recorrido].izq != 0) {
            Reco.put(arbol[recorrido].izq);
        }
        if (arbol[recorrido].der != 0) {
            Reco.put(arbol[recorrido].der);
        }
        recorrido = Reco.get();
        if (recorrido == final) {
            cout << arbol[recorrido].info << endl;
            recorrido = 0;
        }
    }
}


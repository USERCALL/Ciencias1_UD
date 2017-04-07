#ifndef ARBOL_H
#define ARBOL_H
#include <cstdlib>
#include <iostream>
#include "Pila.h"
#include "Colas.h"

using namespace std;

struct Nod{
	int info , izq , der;
};

class Arbol{
	
	int tamanio;
    Pila <int> Rec(5);
    //Pila <int> Rec;
    Colas <int> Reco;
    
	public: 
		Arbol(){}
		/*
        void inicio(int t);
        void insertar (int info);
        int buscar (int info);
        void eliminar (int info);
        void inorden();
        void preorden();
        void pornivel();
        */
	void inicio(int t){
    tamanio = t;
    Nod arbol[tamanio];
    arbol[0].izq = 0;
    arbol[0].der = 1;
    int i;
	for(i=1,i<(tamanio-1);i++){
    	arbol[i].der = i+1;
    }
    arbol[tamanio-1].der = 0;
}

void insertar (int info){
    int aux , aux2 , raiz;
    if (arbol[0].izq == 0){
        arbol[0].izq = 1;
        arbol[0].der = arbol[1].der;
        arbol[1].info = info;
        arbol[1].izq = 0;
        arbol[1].der = 0;
    }else{
        aux = arbol[0].der;
        raiz = arbol[0].izq;
        aux2 = raiz;
        if (aux != 0){
            arbol[0].der = arbol[aux].der;
            arbol[aux].info = info;
            arbol[aux].izq = 0;
            arbol[aux].der = 0;
            while (raiz != 0){
                if (arbol[raiz].info > arbol[aux].info){
                    aux2 = raiz;
                    raiz = arbol[raiz].izq;
                }else{
                    aux2 = raiz;
                    raiz = arbol[raiz].der;
                }
            }
            if (arbol[aux2].info > arbol[aux].info){
                arbol[aux2].izq = aux;
            }else{
                arbol[aux2].der = aux;
            }
         }else{
             cout<<"No se pueden agregar mas elementos"<<endl;
         }
     }
}

int buscar (int info){
	int pos;
	pos = arbol[0].izq;
	while (arbol[pos].info != info){
        if (arbol[pos].info > info){
            pos = arbol[pos].izq;
        }else{
            pos = arbol[pos].der;
        }
    }
	if (pos == 0){
		cout<<"No se encontro "<<info<<endl;
		return 0;
	}else{
		return pos;
	}
}

void eliminar (int info){
	int raiz , pos , hoja , padre;
	raiz = arbol[0].izq;
	pos = buscar(info);
	while (arbol[raiz].der != pos && arbol[raiz].izq != pos){
		if (arbol[raiz].info > info){
            raiz = arbol[raiz].izq;
        }else{
            raiz = arbol[raiz].der;
        }
	}
	if (pos != 0){
		if (arbol[pos].izq == 0 && arbol[pos].der == 0){
            if (arbol[0].izq == pos){
            }else{
			    if(arbol[raiz].der == pos){
				   arbol[raiz].der = 0;
			    }else{
			       arbol[raiz].izq = 0;
			    }
			}

		}
		if (arbol[pos].izq != 0 && arbol[pos].der == 0){
            hoja = arbol[pos].izq;
            if (arbol[raiz].izq == pos){
                 arbol[raiz].izq = hoja;
            }else{
                 arbol[raiz].der = hoja;
            }
            if (arbol[0].izq == pos){
                arbol[0].izq = hoja;
            }
        }
        if (arbol[pos].izq == 0 && arbol[pos].der != 0){
            hoja = arbol[pos].der;
            if (arbol[raiz].izq == pos){
                 arbol[raiz].izq = hoja;
            }else{
                 arbol[raiz].der = hoja;
            }
            if (arbol[0].izq == pos){
                arbol[0].izq = hoja;
            }
        }
        if (arbol[pos].izq != 0 && arbol[pos].der != 0){
            padre = pos;
            hoja = arbol[pos].der;
            while (arbol[hoja].izq != 0){
                  padre = hoja;
                  hoja = arbol[hoja].izq;
            }
            if (arbol[padre].izq == hoja){
                  arbol[padre].izq = 0;
                  if (arbol[hoja].der != 0){
                       arbol[padre].izq = arbol[hoja].der;
                  }
            }else{
                  arbol[padre].der = 0;
            }
            arbol[hoja].izq = arbol[pos].izq;
            arbol[hoja].der = arbol[pos].der;
            if (arbol[raiz].izq == pos){
                arbol[raiz].izq = hoja;
            }else{
                arbol[raiz].der = hoja;
            }
            if (arbol[0].izq == pos){
                arbol[0].izq = hoja;
            }
        }
        arbol[pos].info = 0;
		arbol[pos].izq = 0;
		arbol[pos].der = arbol[0].der;
		arbol[0].der = pos;
   }
}

void inorden(){
     int recorrido , final;
     recorrido = arbol[0].izq;
     final = arbol[0].izq;
     while (arbol[final].der != 0){
           final = arbol[final].der;
     }
     while (recorrido != 0){
           if (arbol[recorrido].izq != 0){
               Rec.push(recorrido);
               recorrido = arbol[recorrido].izq;
           }else{
               cout<<arbol[recorrido].info<<" ";
               if (arbol[recorrido].der != 0){
                   recorrido = arbol[recorrido].der;
               }else{
                   recorrido = Rec.pop();
                   cout<<arbol[recorrido].info<<" ";
                   if (arbol[recorrido].der != 0){
                       recorrido = arbol[recorrido].der;
                   }else{
                       recorrido = Rec.pop();
                       cout<<arbol[recorrido].info<<" ";
                       recorrido = arbol[recorrido].der;
                   }
               }
           }
           if (recorrido == final){
               cout<<arbol[recorrido].info<<endl;
               recorrido = 0;
           }
     }
}

void preorden(){
     int recorrido , final;
     recorrido = arbol[0].izq;
     final = arbol[0].izq;
     while (arbol[final].der != 0){
           final = arbol[final].der;
     }
     while (recorrido != 0){
           if (arbol[recorrido].izq != 0){
               cout<<arbol[recorrido].info<<" ";
               Rec.push(recorrido);
               recorrido = arbol[recorrido].izq;
           }else{
               cout<<arbol[recorrido].info<<" ";
               if (arbol[recorrido].der != 0){
                  cout<<arbol[arbol[recorrido].der].info<<" ";
               }
               recorrido = Rec.pop();
               while (arbol[recorrido].der == 0){
                     recorrido = Rec.pop();
               }
               recorrido = arbol[recorrido].der;
           }
           if (recorrido == final){
               cout<<arbol[recorrido].info<<endl;
               recorrido = 0;
           }
     }
}

void pornivel(){
     int recorrido , final;
     recorrido = arbol[0].izq;
     final = arbol[0].izq;
     while (arbol[final].der != 0){
           final = arbol[final].der;
    }
     while (recorrido != 0){
        cout<<arbol[recorrido].info<<" ";
        if (arbol[recorrido].izq != 0){
            Reco.put(arbol[recorrido].izq);
        }
        if (arbol[recorrido].der != 0){
            Reco.put(arbol[recorrido].der);
        }
        recorrido = Reco.get();
        if (recorrido == final){
    	    cout<<arbol[recorrido].info<<endl;
            recorrido = 0;
        }
    }
}

};


#endif

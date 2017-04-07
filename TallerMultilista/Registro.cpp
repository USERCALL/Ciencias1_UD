/**
/ Clase que implementa los métodos definidos en el header de la clase Registro
/ Autor: Alba Consuelo Nieto
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include "Registro.h"
/*---------------------------
/ Constructor de la clase
/*--------------------------*/
Registro:: Registro(){
    cabEst = NULL;
}
/**
/ Inserta un nuevo nodo  al final de la lista.
/ Parámetros: codigo: Número entero con el código del estudiante
/             nombre: Nombre del estudiante       
*/
void Registro::insertarEstudiante(int codigo, string nombre){
    est *p;
    darLastEst(p);  //Busca el apuntador del último nodo de la lista
    insertarNodoEst(p, NULL, codigo, nombre);
}
/**
/ Retorna el apuntador al último nodo de la lista.
/ Parámetros: p : Apuntador que se recibe por referencia; en él se retorna 
/                 el apuntador al último nodo de la lista
*/
void Registro::darLastEst(est * &p){
        p = cabEst;
        // Recorre la lista desde la cabeza hasta encontrar el último nodo
        while(p != NULL && p->sig != NULL){
            if (p-> sig != NULL){
                p = p -> sig;
            }
        }
        
}
/**
/ Inserta un nuevo nodo con los datos del estudiante entre los nodos con apuntadores p y q
/ Parámetros: p y q : Apuntadores a los nodos entre los que se inserta el nuevo nodo
/             codigo: Número entero que corresponde al código del estudiante
/             nombre: Nombre del estudiante 
*/
void Registro::insertarNodoEst(est *p, est *q, int codigo, string nombre){
	est *nuevo;
	nuevo = new (est);
	/** TODO. Inserte el nodo nuevo entre los con apuntadores p y q.
              Tenga en cuenta que la lista puede estar vacía*/
}
/**
/  Busca si el nodo con el código dado como parámetro está en la lista
/  Parámetros: codigo: Código del estudiante a buscar 
/              pos   : Posición del nodo dentro de la lista; si no está retorna 0.
/              encontre : Variable booleana. Retorna true si el código está en la lista 
/                         o false en caso contrario                              
*/
void Registro::buscarCodigo(int n, int &pos, bool &encontre){
 est *ant, *act;
 buscarNodo(n,pos, encontre, ant,act);
}
/**
/  Busca si el nodo con el código dado como parámetro está en la lista
/  Parámetros: codigo: Código del estudiante a buscar 
/              pos   : Posición del nodo dentro de la lista; si no está retorna 0.
/              encontre : Variable booleana. Retorna true si el código está en la lista 
/                         o false en caso contrario 
/              ant      : Apuntador al nodo anterior al nodo buscado
/              act      : Apuntador al nodo buscado.                                
*/
void Registro::buscarNodo(int n, int &pos, bool &encontre, est *&ant, est *&act )
{
	ant = NULL;
	act = cabEst;
    encontre = false;
	pos = 0;
	/** TODO. Recorrer la lista para buscar el nodo con código = n. Si lo encuentra debe hacer 
              encontre = true, ant=nodo anterior, act=nodo actual y pos= posición del nodo */
}
/**
/  Recibe el código del estudiante, busca el nodo en la lista y le asocia la lista de materias 
/  recibidas como parámetro
/  Parámetros : codigo : Código del estudiante 
/               m      : Apuntador a la cabeza de la lista de materias 
*/
void Registro::asociarMaterias(int codigo, Materia::materia *m){
     est *ant, *act;
     int pos;
     bool encontre;
     /**TODO Invocar el método buscarNodo con los parámetros requeridos */
     if (encontre){
         /**TODO. Asociarle al nodo act la lista de materias */
     }
     else
       cout << " \nNo se encuentra el código " << codigo;
}
/**
/ Recorre la lista de estudiantes, imprime el código, nombre y lista de materias asignadas
*/
void Registro::imprimirLista(){
    Materia::materia *tmpMat;
	est *tmpEst = cabEst;
    while (tmpEst != NULL){
	    printf("\nCODIGO: %2d", tmpEst -> codigo);
	    cout << "\tNOMBRE: " << tmpEst -> nombre << "\n";
	  
        tmpEst = tmpEst -> sig;
        cout << "\n\n";
	}
}

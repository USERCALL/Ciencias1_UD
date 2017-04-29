/**
/ Clase que implementa los m�todos definidos en el header de la clase Registro
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
/ Par�metros: codigo: N�mero entero con el c�digo del estudiante
/             nombre: Nombre del estudiante       
*/
void Registro::insertarEstudiante(int codigo, string nombre){
    est *p;
    darLastEst(p);  //Busca el apuntador del �ltimo nodo de la lista
    insertarNodoEst(p, NULL, codigo, nombre);
}
/**
/ Retorna el apuntador al �ltimo nodo de la lista.
/ Par�metros: p : Apuntador que se recibe por referencia; en �l se retorna 
/                 el apuntador al �ltimo nodo de la lista
*/
void Registro::darLastEst(est * &p){
        p = cabEst;
        // Recorre la lista desde la cabeza hasta encontrar el �ltimo nodo
        while(p != NULL && p->sig != NULL){
            if (p-> sig != NULL){
                p = p -> sig;
            }
        }
        
}
/**
/ Inserta un nuevo nodo con los datos del estudiante entre los nodos con apuntadores p y q
/ Par�metros: p y q : Apuntadores a los nodos entre los que se inserta el nuevo nodo
/             codigo: N�mero entero que corresponde al c�digo del estudiante
/             nombre: Nombre del estudiante 
*/
void Registro::insertarNodoEst(est *p, est *q, int codigo, string nombre){
	est *nuevo;
	nuevo = new (est);
	/** TODO. Inserte el nodo nuevo entre los con apuntadores p y q.
              Tenga en cuenta que la lista puede estar vac�a*/
}
/**
/  Busca si el nodo con el c�digo dado como par�metro est� en la lista
/  Par�metros: codigo: C�digo del estudiante a buscar 
/              pos   : Posici�n del nodo dentro de la lista; si no est� retorna 0.
/              encontre : Variable booleana. Retorna true si el c�digo est� en la lista 
/                         o false en caso contrario                              
*/
void Registro::buscarCodigo(int n, int &pos, bool &encontre){
 est *ant, *act;
 buscarNodo(n,pos, encontre, ant,act);
}
/**
/  Busca si el nodo con el c�digo dado como par�metro est� en la lista
/  Par�metros: codigo: C�digo del estudiante a buscar 
/              pos   : Posici�n del nodo dentro de la lista; si no est� retorna 0.
/              encontre : Variable booleana. Retorna true si el c�digo est� en la lista 
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
	/** TODO. Recorrer la lista para buscar el nodo con c�digo = n. Si lo encuentra debe hacer 
              encontre = true, ant=nodo anterior, act=nodo actual y pos= posici�n del nodo */
}
/**
/  Recibe el c�digo del estudiante, busca el nodo en la lista y le asocia la lista de materias 
/  recibidas como par�metro
/  Par�metros : codigo : C�digo del estudiante 
/               m      : Apuntador a la cabeza de la lista de materias 
*/
void Registro::asociarMaterias(int codigo, Materia::materia *m){
     est *ant, *act;
     int pos;
     bool encontre;
     /**TODO Invocar el m�todo buscarNodo con los par�metros requeridos */
     if (encontre){
         /**TODO. Asociarle al nodo act la lista de materias */
     }
     else
       cout << " \nNo se encuentra el c�digo " << codigo;
}
/**
/ Recorre la lista de estudiantes, imprime el c�digo, nombre y lista de materias asignadas
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

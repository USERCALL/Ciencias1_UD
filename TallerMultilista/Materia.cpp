/**
/ Clase que implementa los m�todos definidos en el header de la clase Materia
/ Autor: Alba Consuelo Nieto
*/
#include <iostream>
#include <stdio.h>
#include <string>
#include "Materia.h"

/**-----------------------------
/  Constructor de la clase
/-------------------------------*/
Materia:: Materia(){
    cabMat = NULL;
}
/**
/  Inserta al final de la lista de materias una nueva materia con su nota
*/
void Materia::insertarMateria(string nombre, float nota){
    struct materia *p;
    darLastMat(p);
    insertarNodoMat(p, NULL, nombre, nota);
}
/**
/ Retorna el apuntador al �ltimo nodo de la lista.
/ Par�metros: p : Apuntador que se recibe por referencia; en �l se retorna el apuntador al �ltimo nodo de la lista
*/
void Materia::darLastMat(struct materia * &p){
        p = cabMat;
        /** TODO. Recorra la lista para encontrar el apuntador al �ltimo nodo de la lista. 
            Se debe retornar en la variable p*/
        
}
/**
/ Inserta un nuevo nodo con el nombre de la materia y la nota entre los nodos con apuntadores p y q
/ Par�metros: p y q : Apuntadores a los nodos entre los que se inserta el nuevo nodo
/             nombre: Nombre de la materia
/             nota  : N�mero real que corresponde a la nota de la materia 
*/
void Materia::insertarNodoMat(mat *p, mat *q, string nombre, float nota){
  /** TODO. Cree el nuevo nodo de tipo apuntador a materia e ins�rtelo entre los nodos con apuntadores p y q. 
            Tenga en cuenta que la lista puede estar vac�a*/
}

/**
/  Retorna la cabeza de la lista de materias
*/
Materia::materia* Materia::darCabeza(){
    return cabMat;
}

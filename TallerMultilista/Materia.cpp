/**
/ Clase que implementa los métodos definidos en el header de la clase Materia
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
/ Retorna el apuntador al último nodo de la lista.
/ Parámetros: p : Apuntador que se recibe por referencia; en él se retorna el apuntador al último nodo de la lista
*/
void Materia::darLastMat(struct materia * &p){
        p = cabMat;
        /** TODO. Recorra la lista para encontrar el apuntador al último nodo de la lista. 
            Se debe retornar en la variable p*/
        
}
/**
/ Inserta un nuevo nodo con el nombre de la materia y la nota entre los nodos con apuntadores p y q
/ Parámetros: p y q : Apuntadores a los nodos entre los que se inserta el nuevo nodo
/             nombre: Nombre de la materia
/             nota  : Número real que corresponde a la nota de la materia 
*/
void Materia::insertarNodoMat(mat *p, mat *q, string nombre, float nota){
  /** TODO. Cree el nuevo nodo de tipo apuntador a materia e insértelo entre los nodos con apuntadores p y q. 
            Tenga en cuenta que la lista puede estar vacía*/
}

/**
/  Retorna la cabeza de la lista de materias
*/
Materia::materia* Materia::darCabeza(){
    return cabMat;
}

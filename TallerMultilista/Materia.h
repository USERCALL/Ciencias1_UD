/**TDA de la lista de Materias
* Define las siguientes operaciones básicas sobre la lista: insertarMateria, darCabeza
* Autor: Alba Consuelo Nieto
*/
#ifndef _MATERIA_H
#define _MATERIA_H
#include <string>
using namespace std;
class Materia{
	public:
        typedef struct materia{  //Definición del tipo nodo materia
		string nombre;
		float  nota;
		struct materia *sig;
		} mat;
		
		
        Materia();   //Constructor de la clase
		void insertarMateria(string nombre, float nota);
		Materia::materia* darCabeza();
		
	private:
		mat *cabMat;           //Apuntador a la cabeza de lista de materias
		void insertarNodoMat(mat *p, struct materia *q, string nombre, float nota);
		void darLastMat(mat * &p);
	
};
#endif

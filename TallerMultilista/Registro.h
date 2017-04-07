/**TDA de la lista de Estudiantes
* Define las siguientes operaciones básicas sobre la lista: imprimirLista,insertarEstudiante, buscarCodigo, asociarMaterias
* Autor: Alba Consuelo Nieto
*/
#include <string>
#include "Materia.h"
using namespace std;
class Registro{
	private:
        /*--------------------------------
        / Atributos de la clase
        /--------------------------------*/
		typedef struct estudiante{ //Definición del nodo estrudiante
		string nombre;
		int  codigo;
		/**TODO Definir el apuntador a la lista de materias */
		struct estudiante *sig;   //Apuntador al siguiente nodo de estudiante
		} est;

		est *cabEst;   
        /*-----------------------------          
        / Métodos privados
        /------------------------------*/
	    void insertarNodoEst(est *p, est *q, int codigo, string nombre);
	    void buscarNodo(int n, int &pos, bool &encontre, est *&ant, est *&act);
     	void darLastEst(est * &p);
		
    public:
        /*----------------------------
        / Métodos públicos de la clase
        /-----------------------------*/
        Registro();
		void imprimirLista();
		void insertarEstudiante(int codigo,string nombre);
		void buscarCodigo(int n, int &pos, bool &encontre);
		void asociarMaterias(int codigo, Materia::materia *m);
};

#include <cstdlib>
#include <iostream>
#include "Registro.h"
#include "Materia.h"

using namespace std;
/**
Programa principal de prueba
*/
int main(int argc, char *argv[])
{
    
    Registro r = Registro();
    r.insertarEstudiante(1, "Luis");
    r.insertarEstudiante(2, "Maria");
    r.insertarEstudiante(3, "Jose");
    
    Materia m = Materia();
    m.insertarMateria("CCI", 5.0);
    m.insertarMateria("Calculo", 3.0);
    m.insertarMateria("Fisica", 2.5);
    r.asociarMaterias(1, m.darCabeza());
   
    m = Materia();
    m.insertarMateria("CCII", 5.0);
    m.insertarMateria("Fisica", 3.5);
    r.asociarMaterias(3, m.darCabeza());
    
    r.imprimirLista();
   
    cout << "\n";
    system("PAUSE");
    return EXIT_SUCCESS;
}

/******************************************************************************
codigo  Arboles binarios con arreglos
******************************************************************************/

//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058
//Ciencias Computacion I  (2017-04-17)


#include <cstdlib>
#include <iostream>
#include "Arbol.h"

using namespace std;

int main(int argc, char *argv[])
{
    Arbol Bin;
    Bin.inicio(14);
    insertar(100);
    insertar(150);
    insertar(50);
    insertar(30);
    insertar(75);
    insertar(125);
    insertar(170);
    insertar(10);
    insertar(60);
    insertar(90);
    insertar(180);
    insertar(140);
    insertar(160);
    
    
    
    cout<<"Inorden:"<<endl;
    inorden();
    cout<<"Preorden:"<<endl;
    preorden();
    cout<<"Pornivel:"<<endl;
    pornivel();
    cout<<"---------------------------------"<<endl;
    cout<<"Raiz:"<<arbol[0].izq<<endl;
    cout<<"Vacio:"<<arbol[0].der<<endl;
    cout<<"Info 1:"<<arbol[1].info<<endl;
    cout<<"Izq 1:"<<arbol[1].izq<<endl;
    cout<<"Der 1:"<<arbol[1].der<<endl;
    cout<<"Info 2:"<<arbol[2].info<<endl;
    cout<<"Izq 2:"<<arbol[2].izq<<endl;
    cout<<"Der 2:"<<arbol[2].der<<endl;
    cout<<"Info 3:"<<arbol[3].info<<endl;
    cout<<"Izq 3:"<<arbol[3].izq<<endl;
    cout<<"Der 3:"<<arbol[3].der<<endl;
    cout<<"Info 4:"<<arbol[4].info<<endl;
    cout<<"Izq 4:"<<arbol[4].izq<<endl;
    cout<<"Der 4:"<<arbol[4].der<<endl;
    cout<<"Info 5:"<<arbol[5].info<<endl;
    cout<<"Izq 5:"<<arbol[5].izq<<endl;
    cout<<"Der 5:"<<arbol[5].der<<endl;
    cout<<"Info 6:"<<arbol[6].info<<endl;
    cout<<"Izq 6:"<<arbol[6].izq<<endl;
    cout<<"Der 6:"<<arbol[6].der<<endl;
    cout<<"Info 7:"<<arbol[7].info<<endl;
    cout<<"Izq 7:"<<arbol[7].izq<<endl;
    cout<<"Der 7:"<<arbol[7].der<<endl;
    cout<<"Info 8:"<<arbol[8].info<<endl;
    cout<<"Izq 8:"<<arbol[8].izq<<endl;
    cout<<"Der 8:"<<arbol[8].der<<endl;
    cout<<"Info 9:"<<arbol[9].info<<endl;
    cout<<"Izq 9:"<<arbol[9].izq<<endl;
    cout<<"Der 9:"<<arbol[9].der<<endl;
    cout<<"Info 10:"<<arbol[10].info<<endl;
    cout<<"Izq 10:"<<arbol[10].izq<<endl;
    cout<<"Der 10:"<<arbol[10].der<<endl;
    cout<<"Info 11:"<<arbol[11].info<<endl;
    cout<<"Izq 11:"<<arbol[11].izq<<endl;
    cout<<"Der 11:"<<arbol[11].der<<endl;
    cout<<"Info 12:"<<arbol[12].info<<endl;
    cout<<"Izq 12:"<<arbol[12].izq<<endl;
    cout<<"Der 12:"<<arbol[12].der<<endl;
    cout<<"Info 13:"<<arbol[13].info<<endl;
    cout<<"Izq 13:"<<arbol[13].izq<<endl;
    cout<<"Der 13:"<<arbol[13].der<<endl;*/
    system("PAUSE");
    return EXIT_SUCCESS;
}

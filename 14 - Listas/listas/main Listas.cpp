#include <cstdlib>
#include <iostream>
#include <time.h>
#include "Lista.h"

using namespace std;

int main(int argc, char *argv[])
{
	Lista <int>Info;
	int info;
	Info.insertar_pos(3,1);
	Info.insertar_inicio(9);
	Info.insertar_final(6);
	Info.imprimir();
    /*ColasDobles <int>Info;
    int info;
    Info.enqueve(3,I);
    Info.enqueve(8,D);
    Info.enqueve(10,I);
    info = Info.dequeve(D);
    cout<<"Dato sacado:"<<endl;
    cout<<info<<endl;*/
    system("PAUSE");
    return EXIT_SUCCESS;
}

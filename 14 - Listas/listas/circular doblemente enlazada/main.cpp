#include <iostream>
#include <stdio.h>
#include <conio.h>
#include "Lista.h"
#include <cstdlib>
#include <time.h>


int main(int argc, char *argv[])
{int dato1, dato2, i, j, longitud;
 Lista <int>X;
 srand(time(NULL));
 longitud= 10+rand()%5;
 cout<<"El tamaño de la lista es: "<<longitud<<endl<<endl;
 for(i=1; i<=longitud; i++)
    X.insertarFinal(1+(rand()%151));
 longitud=X.listaTam();
 X.imprimirLista() ;
  system("PAUSE");

 if(longitud >0)
   {for(i=1; i<=longitud-1; i++)
     for(j=i+1; j<=longitud; j++)
      {dato1=X.buscarElemento(i);
       dato2=X.buscarElemento(j);
       if (dato1 > dato2)
          {X.borrarElemento(j);
           X.borrarElemento(i);
           X.insertar_pos(i,dato2);
           X.insertar_pos(j,dato1);
          }
      }
    X.imprimirLista();  
    }      
    system("PAUSE");    
    return EXIT_SUCCESS;
}



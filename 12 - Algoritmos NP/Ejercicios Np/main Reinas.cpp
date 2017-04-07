#include <cstdlib>
#include <iostream>
#include <fstream>
#include <time.h>

using namespace std;

int DIMENSION =33;

bool colocarReina (int **t, int fila);
void imprimir(int **lab);
bool amenazada(int **t, int fila, int columna);


int main(int argc, char *argv[])
{
    ofstream P;
    P.open("Reinas.txt", ios::out | ios::app);
        
    if(P.fail()){
       cout<<"No se ha podido guardar los datos";
       system("cls"); 
    }
 double ini,fin; 
 int DIM=DIMENSION;
 for(int m=8;m<DIM;m++){
 int **t;
 cout<<"Reinas: "<<m<<endl;
 DIMENSION=m;
 t= new int*[DIMENSION];
 for (int i=0; i< DIMENSION; i++)
      t[i]= new int[DIMENSION];
 for (int j=0; j< DIMENSION; j++){
 	for (int k=0; k< DIMENSION; k++){
 		t[j][k]=0;
	 }
 }
 ini=clock();
 colocarReina(t,0);
 fin=clock();
 P<<"El tiempo que se demora en ejecutar con "<<m<<" reinas es de:"<<" "<<fin-ini<<endl;
 }
 P.close();
    system("PAUSE");
    return EXIT_SUCCESS;
}

bool colocarReina (int **t, int fila)
{bool tmp;
if(fila == DIMENSION){
    /*cout<< "solucion encontrada \n";
    imprimir(t);*/
    return true;}

for(int columna=0; columna<=DIMENSION; columna++)
 {  if (!amenazada(t, fila, columna)){
       t[fila][columna]= fila + 1; // reina i-esima
       tmp= colocarReina(t, fila+1);
       if (tmp==true) return true;
       //borra solucion invalida
       t[fila][columna]=0;
     }
 }
 return false;
}

void imprimir(int **lab)
{for (int i =0; i<DIMENSION; i++)
    {for (int j =0; j<DIMENSION; j++)
        cout<<lab[i][j];
     cout<<endl;
    }
}

bool amenazada(int **t, int fila, int columna)
{int i,f,c;
// revisa fila y columna
for (i=0; i< DIMENSION; i++)
  {if(t[fila][i] != 0 || t[i][columna] !=0) return true;
  }

// arriba a la izquierda  
 for (f=fila, c=columna; f>=0&& c>=0; f--,c--)
 {if(t[f][c] !=0 ) return true;
 }  
 //arriba a la derecha
 for (f=fila, c=columna; f>=0&& c<DIMENSION; f--,c++) 
 {if(t[f][c]!=0) return true; 
 }
 //abajo a la izquierda
 for (f=fila, c=columna; f<DIMENSION&& c>=0; f++,c--)
{if(t[f][c]!=0) return true;}
//abajo derecha
for (f=fila, c=columna; f<DIMENSION&& c<DIMENSION; f++,c++)
{if(t[f][c]!=0) return true;}

return false;
}

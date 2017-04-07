/*
A con k filas y m columnas,
B con m filas y n columnas.
C es la matriz que resulta del producto AB.
C presenta k filas y n columnas.

C[i][j] = A[i][0] * B[0][j] + A[i][1] * B[1][j] + A[i][2] * B[2][j]
+ ... + A[i][m-1] * B[m-1][j]
*/
#include <stdlib.h>
#include <iostream>
#include <conio.h>
#include <time.h>
#include <windows.h>

using namespace std;
/* retorna "a - b" en segundos */

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main()
{
  LARGE_INTEGER t_ini, t_fin;
  double secs;

    int A[20][20], B[20][20], C[20][20];
    int k, m, n;

    cout<<"Lectura de matriz A."<<endl;
    cout<<"Filas de A: "; 
	cin>>k;
    cout<<"Columnas de A: "; cin>>m;
    cout<<endl;
 //   srand(time(0));
    for(int i=0; i<k; ++i){
	
        for(int j=0; j<m; ++j)
        {
           A[i][j]=rand()%50;
           printf("\t%d",A[i][j]);
        }
        printf ("\n\n");
	}
    cout<<"Lectura de matriz B:"<<endl;
    cout<<"Filas de B: "<<m<<" (ya esta definido y es necesario)."<<endl;
    cout<<"Columnas de B: "; 
	cin>>n;
    cout<<endl;
    for(int i=0; i<m; ++i){
	
        for(int j=0; j<n; ++j)
        {
           B[i][j]=rand()%50;
           printf("\t%d",B[i][j]);
        }
        printf("\n\n");
	}
    // Inicializamos la matriz C.
    for(int i=0; i<k; ++i)
        for(int j=0; j<n; ++j)
            C[i][j] = 0;

  
 
 
 
 QueryPerformanceCounter(&t_ini);
  /* ...hacer algo... */
 
      // Generamos la matriz C.
      //multiplicacion y calculo
    for(int i=0; i<k; ++i)
	    for(int j=0; j<n; ++j)
            for(int z=0; z<m; ++z)
                C[i][j] += A[i][z] * B[z][j];
  QueryPerformanceCounter(&t_fin);

  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("el tiempo gastado en la operación es:");
  printf("%.16g milliseconds\n", secs * 1000.0);
  
 
 
 
 
  cout<<"Matriz C: "<<endl;
  for(int i=0; i<k; ++i)
    {
        for(int j=0; j<n; ++j)
        {
            printf("\t%d", C[i][j]);
        }
        printf("\n\n");
    }
    
    return 0;
}

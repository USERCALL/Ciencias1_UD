#include <iostream>
#include <windows.h>
#include <stdio.h>
#include <stdlib.h> 
#include <conio.h>
#include <time.h> 

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

using namespace std;


 
int main(int argc, char** argv) {
 
 int n,m;
 int matrizA[n][m],matrizB[m][n];// matrizC[0][0];
 cin>>n;//numero de filas
 cin>>m; //numero de columnas

 matrizA[n][m];
 matrizB[m][n];
 //matrizC[n][n];
printf("la matriz A: \n");

    for (int i=0;i<n;i++)
    {
        for (int j=0;j<m;j++)
        {
            matrizA[i][j]=rand()%50;//Agrega numero aleatorio a la posicion ij de la matriz
            printf("\t%d",matrizA[i][j]);//imprime elemento de la matriz en pantalla
        }
      printf("\n\n");//para dejar espacios entre filas.
    }

 printf("\n");
 printf("la matriz B: \n");  
  printf("\n");
    
    for (int a=0;a<m;a++)
    {
        for (int b=0;b<n;b++)
        {
            matrizB[a][b]=rand()%50;//Agrega numero aleatorio a la posicion ij de la matriz
            printf("\t%d",matrizB[a][b]);//imprime elemento de la matriz en pantalla
        }
      printf("\n\n");//para dejar espacios entre filas.
    }
  printf("\n\n");//para dejar espacios entre filas.
  
     printf("\n la matriz C");
     printf("\n\n");

	 //multiplicacion de las matrices
	 /*
    for (int c=0;c<n;c++)
	  for(int d=0;d<n;d++)
	  
      {   matrizC[c][d] = 0;
          
		  for(int k=0;k<n;k++)
              matrizC[c][d] = matrizC[c][d] + matrizA[c][d] * matrizB[c][d];
              
			  
			  printf("\t%d",matrizC[c][d]);
      }
 */
	 system("PAUSE");
	return 0;
}
/*
void productoMatrices (int A[DIM][m],int B[DIM][n],int C[DIM][n],int M){
 int i,j,k;
 for (i=0;i<Dim;i++)
     for(j=0;j<Dim;j++)
      {   C[i][j] = 0;
          for(k=0;k<M;k++)
              C[i][j] = C[i][j] + A[i][j] * B[i][j];
      }
 }*/

#include <iostream>
#include "conio.h"
#include <windows.h>
#include <stdio.h>
using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
void burbuja(int[],int);
void imprimir(int[], int);
void intercambio(int[],  int);

double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}


int main(int argc, char** argv) {
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	int i,j,min,a[10],aux,t,N;
	cout<<"ingrese la cantidad de numeros"; cin>>N;
	
		int arr[N];                      
		for(int k=0;k<N;k++){         
			arr[k]=(N-k)*10;
			} 
		QueryPerformanceCounter(&t_ini);
  /* ...hacer algo... */
  		
 		burbuja(arr,N);
  
	QueryPerformanceCounter(&t_fin);
		
  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("%.16g milliseconds\n", secs * 1000.0);
  return 0;
  
  
  
	//burbuja(arr,N);
	
	//imprimir(arr,N);
	
}



void burbuja (int a[], int N)
{
	int i,j;
	
 
   for (i=N;i>1; i--)
      
         for (j=1;j<=i; j++)
	 if(a[j-1]>a[j]) 
         intercambio(a, j);
       
  		
 
 
        }
    
void intercambio (int a[],  int j)
{
		int temp = a[j];
		a[j]=a[j-1];
		a[j-1]=temp;


}

void imprimir (int a[], int N)
{
	int i;
	for(i=0;i<N;i++)
	cout<<a[i]<<" ";
	
}


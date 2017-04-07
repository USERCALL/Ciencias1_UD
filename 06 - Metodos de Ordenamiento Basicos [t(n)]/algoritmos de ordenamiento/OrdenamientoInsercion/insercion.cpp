#include <iostream>
#include "conio.h"
#include <windows.h>
#include <stdio.h>
using namespace std;
void insercion(int[],int);
void imprimir(int[], int);


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
  
  insercion(arr,N);
  
  QueryPerformanceCounter(&t_fin);

  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("%.16g milliseconds\n", secs * 1000.0);
  return 0;
  

	//insercion(arr,N);
	
		//	imprimir(arr,N);
	
}
void insercion( int a[], int N){
	
	int i,j,v;
	for(i=1; i<=N;i++)
		{
			j=i-1;
			v=a[j];
			
	while(a[j-1]>v && j>1)
		{
		a[j]=a[j-1];
		j--	;	
		}
		a[j]=v;
		}
}
void imprimir (int a[], int N)
{
	int i;
	for(i=1;i<=N;i++)
	cout<<a[i]<<" ";
	
}

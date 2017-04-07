#include <iostream>
#include "conio.h"
#include <windows.h>
#include <stdio.h>
using namespace std;

void ordenShell(int a[],int N){
	int i,j,h,v;
	for (h=0;h<=N/9;h=3*h+1);
	for(;h>0;h/=3)
	for(i=h+1;i<=N;i++){
		v=a[i];
		j=i;
		while(j>h-1 && a[j-h]>v){
			a[j]=a[j-h];
			j-=h;
		}
		a[j]=v;
	}
}

void mostrar(int a[], int N)
{
	cout<<endl;
	int j;
	for(j=0; j<N; j++){
     cout<<a[j]<<" ";
	}
	
	
}
double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}

int main(int argc, char** argv) {
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	int N;
	cout<<"ingrese el tamaño del arreglo"<< endl; 
	cin>>N;
	
		int arregloEntero[N];            
		          
		for(int i=0;i<N;i++){         
			arregloEntero[i]=rand()%100;
			cout<<arregloEntero[i]<<" ";
			}
			
			 
	cout << endl;
	
	QueryPerformanceCounter(&t_ini);
  	ordenShell(arregloEntero,N); 	
	QueryPerformanceCounter(&t_fin);
	
	mostrar(arregloEntero,N);
	cout<<endl<<endl;
  secs = performancecounter_diff(&t_fin, &t_ini);
  printf("%.16g milliseconds\n", secs * 1000.0);
  return 0;	
}




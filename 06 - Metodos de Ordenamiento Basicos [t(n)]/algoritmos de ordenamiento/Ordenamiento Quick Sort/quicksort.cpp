
#include <iostream>
#include "conio.h"
#include <windows.h>
#include <stdio.h>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void intercambio(int a[], int min,int i){
	int n=a[i];
	a[i]=a[min];
	a[min]=n;
	
}


void quickSort(int a[], int izquierda, int derecha){
	int i, j, v;
	if (derecha>izquierda){
		v= a[derecha]; 
		i = izquierda -1; 
		j= derecha;
       	for(;;)
            {while (a[++i]<v);
              while (a[--j] >v);
              	if(i>=j) {
			  		break;
			  	}
              intercambio(a,i,j);
             }
       intercambio(a, i, derecha);
       quickSort(a, izquierda, i-1);
       quickSort(a, i+1,derecha);
    }
}


double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}



int main() {
int m;
    LARGE_INTEGER t_ini, t_fin;
	double secs;

cout<<"ingrese el tamaño del arreglo"<<endl;
cin>>m;
		int arregloEntero[m];            
		
		for(int i=0;i<m;i++){         
			arregloEntero[i]=rand()%100;
			cout<<arregloEntero[i]<<" ";
			}          			
			 
	cout << endl;

    QueryPerformanceCounter(&t_ini);
  	quickSort(arregloEntero,0,m-1);
	QueryPerformanceCounter(&t_fin);	
	
	
	cout<<endl;
	cout<<endl;
	 	for(int i=0;i<m;i++){         
			cout<<arregloEntero[i]<<" ";
			} 
	cout<<endl;		
	cout<<"el tiempo que se tardo el algoritmo es: ";
	secs = performancecounter_diff(&t_fin, &t_ini);
    printf("%.16g milliseconds\n", secs * 1000.0);
	   
	return 0;
}

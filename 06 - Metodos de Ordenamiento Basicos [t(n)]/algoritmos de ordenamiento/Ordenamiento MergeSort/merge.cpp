// Merges two subarrays of arr[].
// First subarray is arr[l..m]
// Second subarray is arr[m+1..r]
#include <iostream>
#include "conio.h"
#include <windows.h>
#include <stdio.h>
using namespace std;

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
 
    int L[n1], R[n2];
 
    
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j]; 
    
    i = 0; 
    j = 0; 
    k = l; 
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
/* l is for left index and r is right index of the
   sub-array of arr to be sorted */
void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;
 
        // Sort first and second halves
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
 
        merge(arr, l, m, r);
    }
    
}

    void print(int arr[], int n)
	{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
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
    
	
	int m;
   	cout<<"ingrese el tamaño del arreglo"<< endl; 
	cin>>m;
	
		int arregloEntero[m];            
		
		for(int i=0;i<m;i++){         
			arregloEntero[i]=rand()%100;
			cout<<arregloEntero[i]<<" ";
			}          			
			 
	    cout << endl;
	
         int n = sizeof(arregloEntero)/sizeof(arregloEntero[0]);
	
		QueryPerformanceCounter(&t_ini);
		mergeSort(arregloEntero,0,n);
		QueryPerformanceCounter(&t_fin);
		
			
		cout<<endl;
    	cout<<endl;
    	print(arregloEntero,n);
    	cout<<endl;
		cout<<endl;
	cout<<"el tiempo que se tardo el algoritmo es: ";
	secs = performancecounter_diff(&t_fin, &t_ini);
    printf("%.16g milliseconds\n", secs * 1000.0);
    
    //delete [] arregloEntero;
	  
	}


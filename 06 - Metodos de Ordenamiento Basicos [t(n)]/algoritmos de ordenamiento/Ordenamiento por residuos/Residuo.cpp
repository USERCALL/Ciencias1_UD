#include <iostream>
#include <cstdlib>
#include <windows.h>
#include <fstream>

using namespace std;

unsigned bits (int x, int k, int j){
 return (x>>k)&~(~0<<j);
}


void intercambio (int a[], int i, int j){
int temp = a[i];
a[i]=a[j];
a[j]= temp;
}

void cambioresiduos(int a[], int izq, int der, int b)
{ int i,j,v;
   if (der>izq && b>0)
     {i= izq; j=der;
       while(j!=i)
          {while(!bits(a[i],b,1) && i<j)i++;
            while(bits(a[j],b,1) && j>i)j--;
            intercambio(a, i, j);
    }
           
        if (!bits(a[i],b,1)) 
			j++;
			
            cambioresiduos(a, izq, j-1, b-1);
           
            cambioresiduos(a, j, der, b-1);
      }


}

void print (int a[], int N){
	int i;
	for(i=0;i<N;i++)
	cout<<a[i]<<" ";
	
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
		cambioresiduos(arregloEntero,0,n,1000);
		QueryPerformanceCounter(&t_fin);
		
		cout<<endl;
    	cout<<endl;
    	print(arregloEntero,n);
    	cout<<endl;
		cout<<endl;
	cout<<"el tiempo que se tardo el algoritmo es: ";
	secs = performancecounter_diff(&t_fin, &t_ini);
    printf("%.16g milliseconds\n", secs * 1000.0);
    
  		
   	return 0; 	
}




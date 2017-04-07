#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

void intercambio(int a[],int min,int j){
     int aux=a[min];
     a[min]=a[j];
     a[j]=aux;
}

void Burbuja(int a[],int N){
     double ini, fin;
     int m,n;
     ini=clock();
     for (m=N;m>=0;m--){
         for(n=1;n<=m;n++){
             if(a[n-1]>a[n]){
                intercambio(a,n-1,n);
             }                  
         }                  
     }  
     fin=clock();
     cout<<"El tiempo de ejecucion del proceso 'Burbuja' es de.."<<fin-ini<<endl;
} 

void Insercion(int a[],int N){
     double ini, fin;
     int m,n,v;
     ini=clock();
     for (m=1;m<N;m++){
         n=m;
         v=a[n];
         while(a[n-1]>v && n>0){
            a[n]=a[n-1];
            n--;
         }
         a[n]=v;
     }  
     fin=clock();
     cout<<"El tiempo de ejecucion del proceso 'Insercion' es de.."<<fin-ini<<endl;
} 

void Seleccion(int a[],int N){
     double ini, fin;
     int m,n,min;
     ini=clock();
     for (m=0;m<N-1;m++){
         min=m;
         for(n=m+1;n<N;n++){
            if(a[n]<a[min]){
                 min=n;
			}
     	}
         intercambio(a,min,m);       
     }
     fin=clock();
     cout<<"El tiempo de ejecucion del proceso 'Seleccion' es de.."<<fin-ini<<endl;
}    

int main(int argc, char *argv[])
{
    int i,N;
    int *a;
    N=5;
    //while(N!=7000){
    //cout<<"Tamaño:"<<endl;
    //cout<<N<<endl;//cin>>N;
    a = new int[N];
    for(i=0;i<N;i++){ 
       a[i]=N-i;
	   cout<<a[i]<<endl; 
    }
    //cout<<"Algoritmo de Seleccion"<<endl;
    //Seleccion(a,N); 
    cout<<"Algoritmo de Insercion"<<endl;
    Insercion(a,N); 
    //cout<<"Algoritmo de Burbuja"<<endl;
    //Burbuja(a,N);
    for(i=0;i<N;i++){ 
	   cout<<a[i]<<endl; 
    }
	//N+=1150;
    //}
    system("PAUSE");
    return EXIT_SUCCESS;
}

#include <cstdlib>
#include <iostream>
#include <time.h>

using namespace std;

void Shell (int a[], int N){
     int i,j,h,v;
     double ini,fin;
     ini=clock();
     for(h=0; h<=N/9; h=3*h+1);
     for(; h>0; h/=3)
     for(i=h+1;i<=N; i+=1){
        v=a[i]; 
        j=i;
        while(j >h && a[j-h] > v){
             a[j] = a[j-h]; 
             j-=h;
        }
        a[j]=v;
     }
     fin=clock();
     cout<<"El tiempo de ejecucion es de: "<<fin-ini<<endl;
}
     

int main(int argc, char *argv[])
{
    int i,N;
    int *a;
    cout<<"Tamaño:"<<endl;
    cin>>N;
    a = new int[N];
    //Peor Caso
    for(i=0;i<N;i++){ 
       a[i]=N-i;  
	   //cout<<a[i]<<endl;     
    }
    //Mejor Caso
    /*for(i=1;i<N;i++){ 
       a[i]=i;       
    }*/
    cout<<"Algoritmo de Orden Shell"<<endl;
    Shell(a,N);
	/*for(i=0;i<N;i++){ 
	   cout<<a[i]<<endl;     
    }*/
    system("PAUSE");
    return EXIT_SUCCESS;
}

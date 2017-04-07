#include <cstdlib>
#include <iostream>

using namespace std;

void intercambio(int a[],int min,int j){
     int aux=a[min];
     a[min]=a[j];
     a[j]=aux;
}

void ordenrapido(int a[], int izq, int der){
  int i, j, v;
  if (der > izq){ 
     v = a[der];
     i = izq -1;
     j = der;
     for(;;){
        while (a[++i] < v);
        while (a[--j] > v);
        if(i>=j) break;
        intercambio(a,i,j);
     }
     intercambio(a, i, der);
     ordenrapido(a, izq, i-1);
     ordenrapido(a, i+1,der);
     }
}

int main(int argc, char *argv[])
{
    int i,N;
    double ini,fin;
    cout<<"Tamaño"<<endl;
    cin>>N;
    int a[N];
    //Mejor
    /*for (i=0;i<N;i++){
        a[i]=i+1;
    }*/
    //Peor
    for (i=0;i<N;i++){
        a[i]=N-i;
    }
    cout<<"---------------------"<<endl;
    cout<<"Algoritmo Quick Sort"<<endl;
    ini = clock();
	ordenrapido(a,0,N-1);
	fin = clock();
	cout<<"El tiempo de ejecucion es de: "<<ini<<" "<<fin<<" "<<" "<<fin-ini<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

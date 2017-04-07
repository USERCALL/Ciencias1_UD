#include <cstdlib>
#include <iostream>

using namespace std;

void intercambio(int a[],int min,int j){
     int aux=a[min];
     a[min]=a[j];
     a[j]=aux;
}

int bits (int x, int k, int j){
   return (x>>k)&~(~0<<j);
}

void cambioresiduos(int a[], int izq, int der, int b){
   int i,j,t;
   if (der>izq && b>0){
       i=izq;
	   j=der;
       while(j!=i){
	       while(!bits(a[i],b,1) && i<j)i++;
           while(bits(a[j],b,1) && j>i)j--;
           intercambio(a, i, j);
           }
        if (!bits(a[i],b,1)) j++;
            cambioresiduos(a, izq, j-1, b-1);
            cambioresiduos(a, j, der, b-1);
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
    /*for (i=0;i<N;i++){
        a[i]=N-i;
    }*/
    ini = clock();
	cambioresiduos(a,0,N-1,4);
	fin = clock();
	cout<<"El tiempo de ejecucion es de: "<<ini<<" "<<fin<<" "<<" "<<fin-ini<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

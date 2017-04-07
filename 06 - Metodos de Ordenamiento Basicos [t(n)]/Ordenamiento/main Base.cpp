#include <cstdlib>
#include <iostream>

using namespace std;

int getMax(int arr[], int n)
{
    int mx = arr[0];
    for (int i = 1; i < n; i++)
        if (arr[i] > mx)
            mx = arr[i];
    return mx;
}

void countSort(int arr[], int n, int exp)
{
    int output[n];
    int i, count[10] = {0};
    for (i = 0; i < n; i++)
        count[ (arr[i]/exp)%10 ]++;

    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];

    for (i = n - 1; i >= 0; i--)
    {
        output[count[ (arr[i]/exp)%10 ] - 1] = arr[i];
        count[ (arr[i]/exp)%10 ]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}

void radixsort(int arr[], int n)
{
    int m = getMax(arr, n);
    for (int exp = 1; m/exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
    
int main(int argc, char *argv[]){    
    int i,N,t;
    double ini,fin;
    cout<<"Tamaño"<<endl;
    cin>>N;
    int a[N];
    //Mejor
    for (i=0;i<N;i++){
        a[i]=i+1;
    }
    //Peor
    /*for (i=0;i<N;i++){
        a[i]=N-i;
    }*/
    t = sizeof(a)/sizeof(a[0]);
    cout<<"Algoritmo Radiz Sort"<<endl;   
    ini = clock();
	radixsort(a,t);
	fin = clock();
	cout<<"El tiempo de ejecucion es de: "<<ini<<" "<<fin<<" "<<" "<<fin-ini<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

#include <cstdlib>
#include <iostream>
#include <windows.h>
#include <stdio.h>

using namespace std;

double performancecounter_diff(LARGE_INTEGER *a,LARGE_INTEGER *b){
	LARGE_INTEGER freq;
	QueryPreformanceFrequency(&freq);
	return (double)(a->QuadPart - b->QuadPart)/(double)freq.QuadPart;
}

double iterativo(int n){
     int i;
     double resultado = 1;
     for (i=1;i<=n;i++){
         resultado*=i;
     }   
     return resultado;
}

double recursivo(int n){
     if (n==0 || n==1){
         return 1;
     }else{
         return n*recursivo(n-1);
     }     
}

int main(int argc, char *argv[])
{
    int n;
    double resul;
    LARGE_INTEGER ini,fin,ini1,fin1,t,t1;
    cout<<"Numero"<<endl;
    cin>>n;
    QueryPerformanceCounter(&ini);
    resul = recursivo(n);
    //cout<<"Numero: "<<resul<<endl;
    QueryPerformanceCounter(&fin);
	t=PerformanceCounter_diff(&ini,&fin);
	t=t*1000.0;
    cout<<"El tiempo de ejecucion es de: "<<t<<endl;
    //ini1=clock();
    //resul = iterativo(n);
    //cout<<"Numero: "<<resul<<endl;
    //fin1 = clock();
    //cout<<"El tiempo de ejecucion es de: "<<ini1<<" "<<fin1<<" "<<" "<<fin1-ini1<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

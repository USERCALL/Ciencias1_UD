#include <cstdlib>
#include <iostream>

using namespace std;

double iterativo(int n){
       int i;
       double vo,v1,f;
       vo=0;
       v1=1;
       for (i=0;i<n;i++){
           f=vo+v1;
           vo=v1;
           v1=f;
       }
       return vo;
}

double recursivo(int n){
       if (n==0){
           return 0;
       }else if (n==1){
           return 1;
       }else{
           return recursivo(n-1)+recursivo(n-2);
       }
}      

int main(int argc, char *argv[])
{
    int n;
    double ini,fin,ini1,fin1,resul;
    cout<<"Numero"<<endl;
    cin>>n;
    ini=clock();
    resul = recursivo(n);
    //cout<<"Numero: "<<resul<<endl;
    fin = clock();
    cout<<"El tiempo de ejecucion es de: "<<ini<<" "<<fin<<" "<<" "<<fin-ini<<endl;
    //ini1=clock();
    resul = iterativo(n);
    cout<<"Numero: "<<resul<<endl;
    //fin1 = clock();
    //cout<<"El tiempo de ejecucion es de: "<<ini1<<" "<<fin1<<" "<<" "<<fin1-ini1<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

#include <cstdlib>
#include <iostream>
#include "Pila.h"

using namespace std;

int main(int argc, char *argv[])
{
    int tam,dato,i,x,nue,vie;
    cout<<"Tamaño Pila:"<<endl;
    cin>>tam;
    Pila<int>remplazo(tam);
    Pila<int>aux(tam);
    for (i=1;i<=tam;i++){
        cout<<"Dato "<<i<<":"<<endl;
        cin>>dato;
        remplazo.push(dato);
    }
    cout<<"Numero Viejo:"<<endl;
    cin>>vie;
    cout<<"Numero Nuevo:"<<endl;
    cin>>nue;
    while(!remplazo.vacia()){
        x = remplazo.pop();
        if (x == vie){
              aux.push(nue);
        }else{
              aux.push(x);
        }
        
    }
    while(!aux.vacia()){
        remplazo.push(aux.pop());
    }
    for(i=1;i<=tam;i++){
        cout<<"Dato "<<i<<": "<<remplazo.pop()<<endl;
        
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

#include <cstdlib>
#include <iostream>
#include "Pila.h"

using namespace std;

int main(int argc, char *argv[])
{
    int tam1,tam2,tam3,i,j,x,y,z,dato;
    cout<<"Tamaño Pila 1:"<<endl;
    cin>>tam1;
    Pila<int>primero(tam1);
    cout<<"Tamaño Pila 2:"<<endl;
    cin>>tam2;
    Pila<int>segundo(tam2);
    tam3 = tam1 + tam2;
    Pila<int>resultado(tam3);
    for (i=1;i<=tam1;i++){
        cout<<"Dato "<<i<<":"<<endl;
        cin>>dato;
        primero.push(dato);
    }
    for (j=1;j<=tam2;j++){
        cout<<"Dato "<<j<<":"<<endl;
        cin>>dato;
        segundo.push(dato);
    }
    
    while (!segundo.vacia()){
          resultado.push(segundo.pop());
    }
    
    while (!primero.vacia()){
          segundo.push(primero.pop());
    }
    
    while (!resultado.vacia()){
          primero.push(resultado.pop());
    }
    
    while (!primero.vacia()){
       x = primero.pop();
       cout<<"X: "<<x<<endl;
       if (!segundo.vacia()){
          y = segundo.pop();
          cout<<"Y: "<<y<<endl;
          if (x < y){
                resultado.push(x);
                segundo.push(y);
                cout<<"R: "<<x<<endl;
          }else if (x == y){
                resultado.push(x);
                resultado.push(y);
          }else{
                resultado.push(y);
                primero.push(x);
                cout<<"R: "<<y<<endl;
          }
       }else{
          resultado.push(x); 
       }
    }
    while (!segundo.vacia()){
       y = segundo.pop();
       resultado.push(y); 
       cout<<"R: "<<y<<endl;
    }
    
    while (!resultado.vacia()){
          cout<<"Dato: "<<resultado.pop()<<endl;
    }
    
    system("PAUSE");
    return EXIT_SUCCESS;
}

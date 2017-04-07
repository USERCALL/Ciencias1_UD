#include <cstdlib>
#include <iostream>
#include "Pila.h"

using namespace std;

int fact;
Pila<int>factorial(fact);

int facto(int fact){
    if (factorial.vacia()){
       factorial.push(fact);
       return facto(fact-1);
    }
    if (fact == 0){
            return factorial.pop();
    }
    factorial.push((factorial.pop()*fact)); 
    return facto(fact-1);    
}

int main(int argc, char *argv[])
{
    int i , x;
    cout<<"Escriba el numero:"<<endl;
    cin>>fact;
    x = facto(fact);
    cout<<"El factorial es: "<<x<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

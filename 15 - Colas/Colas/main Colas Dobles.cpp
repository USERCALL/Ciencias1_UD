#include <cstdlib>
#include <iostream>
#include "Cola.h"
#include <time.h>
#include "Colas.h"



using namespace std;

int main(int argc, char *argv[])
{
    Colas <int>C;
    Cola <int>Q;
    C.put(5);
    C.put(8);
    C.put(10);
    cout<<C.get()<<'\t';
    Q.enqueve(5,"I");
    Q.enqueve(8,"I");
    Q.enqueve(10,"D");
    cout<<Q.dequeve("D")<<'\t';
    C.put(15);
    C.put(20);
    C.put(30);
    while (!C.cola_vacia()){
         cout<<C.get()<<'\t'; 
    }
    Q.enqueve(5,"I");
    Q.enqueve(8,"I");
    Q.enqueve(10,"D");
    while (!Q.cola_vacia()){
         cout<<C.dequeve("D")<<'\t'; 
    }
    system("PAUSE");
    return EXIT_SUCCESS;
}

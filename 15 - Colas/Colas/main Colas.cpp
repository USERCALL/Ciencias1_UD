#include <cstdlib>
#include <iostream>
#include <time.h>
#include "Colas.h"

using namespace std;

int main(int argc, char *argv[])
{
    Colas <int>Info;
    int info;
    Info.put(3);
    Info.put(8);
    Info.put(10);
    info = Info.get();
    cout<<"Dato sacado:"<<endl;
    cout<<info<<endl;
    system("PAUSE");
    return EXIT_SUCCESS;
}

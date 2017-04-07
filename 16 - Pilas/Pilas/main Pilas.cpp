#include <iostream>
#include "Pila.h"

using namespace std;

int main(int argc, char** argv) {
    char c;
	Pila<char>guardar(50);
    while(cin.get(c))
    {
	  while(c>='0' && c<='9')
       {cout.put(c); cin.get(c);}
      if (c==')') cout.put(guardar.sacar());
      if (c=='+') guardar.meter(c);
      if (c=='*') guardar.meter(c);
      if (c!='(') cout << ' ';
    }    
    cout<< '\n';
	system("PAUSE");
    return EXIT_SUCCESS;
}

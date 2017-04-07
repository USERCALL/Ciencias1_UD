#include <iostream>

using namespace std;
int cuadrado( int x ) 
{ cout << "Llamada a cuadrado con un argumento int: " << x << endl;
   return x * x; } 

double cuadrado( double y ) 
{ cout << "Llamada a cuadrado con un argumento double: " << y << endl;
   return y * y; }

int main()
{ int resultadoInt = cuadrado( 7 );         // llamada a la versión int
   double resultadoDouble = cuadrado( 7.5 ); // llamada a la versión double

   cout << "\nEl cuadrado del int 7 es " << resultadoInt
        << "\nEl cuadrado del double 7.5 es " << resultadoDouble
        << endl;    

   return 0;
}

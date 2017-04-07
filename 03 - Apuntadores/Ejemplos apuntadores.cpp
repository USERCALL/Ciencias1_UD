#include <iostream>
#include <conio.h>

using namespace std; 

int main(){

int *p; 
p = new int; 

/*funciones por valores, punteros y refencia */


//referencia 
int x = 4;
cout << "Valor de x: " << x << endl;
cout << "Direccion de x: " << &x << endl;



//imprime un numero 
cout << " *p -> "<< *p <<endl; 

//imprime la direccion de memoria como 0xc16fa0
cout << " p -> " <<  p  <<endl;

 *p = 12; 

//imprime un numero despues de asignar *p = 12
cout << " *p -> "<< *p <<endl; 

//imprime un numero 
cout << " &p -> "<< &p <<endl;  






//puntero es un tipo de dato que me almacena la direccion de un tipo de dato 
// int *px = &y;

int y = 5;
int *px = &y;


cout << "valor de y : "<< y <<endl; 
cout << "refencia de y (resulve la direecion de la varaible): "<< &y <<endl;
cout << "puntero px : (tiene almacenada la direccion anteriromente asignada) "<< px <<endl;
cout << "puntero *px (toma el valor de esa direccion): "<< *px <<endl;






/*
Referencias

Además de los punteros heredados de C el lenguaje C++ añadió una nueva
 característica que son las referencias,
 una referencia es por así decirlo un alias o etiqueta de una variable.

Las referencias se deben inicializar al declararse ya que no son en sí una variable sino una etiqueta de otra y se declaran poniendo el operador & después del tipo de dato.

A efectos prácticos n y refn se refieren a la misma variable de hecho si
 con el operador & obtenemos la dirección de memoria de n y refn obtendríamos 
la misma en ambos casos. En nuestra memoria ficticia se vería así:*/


//en este caso c++ 
cout << " \n a una refencia le asigno una variable (&ref_n = n)"<<endl;
int n = 400;
int &ref_n = n;
std::cout << "Direccion de &ref_n " << &ref_n << std::endl;
std::cout << "Direccion de &n " << &n << std::endl;
std::cout << ref_n << std::endl;
std::cout << n << std::endl;




//libera la meoria en p
delete p; 

getch();


}


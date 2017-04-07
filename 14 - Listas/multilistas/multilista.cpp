#include <iostream>

using namespace std;
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

struct Dato{
	//string nombre,carrera,hooby;
	string nombre; int  sig_nombre;
	int edad; int sig_edad;
	//int edad, sig_nombre, sig_carrera,sig_edad,sig_hooby;
};

struct cabeceras{
	string atributo;
	int pos;
};



int main(int argc, char** argv) {
	string nombre;
	cabeceras c[2];
	c[0].atributo="nombre";
	c[1].atributo="edad";
	
	/*
    c[0].atributo= "nombre";
    c[1].atributo= "Ing.Electronica";
    c[2].atributo= "Ing.Industrial";
    c[3].atributo= "Ing.Sistemas";
    c[4].atributo= "edad";
    c[5].atributo= "Danza";
    c[6].atributo= "Natacion";
    c[7].atributo= "Basket";
    c[8].atributo= "Baseball";
    */
    for(int i=0; i<2; i++){
     c[i].pos=0;	
	}
    
    
	
	
	Dato d[11];
	
	for(int j=1; j<=10; j++){
		cout<<"ingrese el nombre"<<endl;
		cin>>nombre;
		d[j].nombre=nombre;
		d[j].sig_nombre=j;
		/*if(c[0].atributo==""){
			c[0].atributo=nombre;
		}
		else{
			if(c[0].atributo<nombre){
				c[0].atributo;
			}
			else
				c[0].atributo=nombre;
		}*/
		if(d[j].nombre==""){
			d[j].nombre=nombre;
		}
		else{
			d[j].nombre=nombre;
			if(d[j].nombre<d[j-1].nombre){
				d[j--].nombre;
				d[j].nombre=nombre;
			}
			else 
				d[j].nombre;
				d[j++].nombre=nombre;
		}
	}
	
	cout<<c[0].atributo<<endl;
	for(int jk=1; jk<=10; jk++){
		cout<<"el nombre es "<<d[jk].nombre<<endl; 
	}
	
	
	system("PAUSE");
		
	return 0;
}

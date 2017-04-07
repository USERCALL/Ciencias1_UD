#include <iostream>
#include "Lista.h"

using namespace std;

struct tarjetas{
	string color,causa;
	int dia,mes,year;	
};

struct jugador{
	string nombre,posic;
	int edad;
	Lista<tarjetas> t;
};

struct equipo{
	string nombre,region,entrenador;
	Lista<jugador> j;
};


int main(int argc, char** argv) {
		
	int cant_jug,cant_tarj,cant_Equ;
	string nombre_equipo,entrenador,region;	
	string nombre_jugador,posic;
	int edad;
	string color,causa;
	int dia,mes,year; 
	Lista<equipo> equipos;

	cout<<"ingrese la cantidad de equipos:"<<endl;
	cin>>cant_Equ;

    equipo equipo[cant_Equ];
 
 	if(cant_Equ!=0){
 	
 		for(int i=0;i<cant_Equ;i++){
		
		cout<<"Equipo No "<<i+1<<": "<<endl;
		cout<<"Ingrese el nombre del equipo "<<endl;
	 	cin>>nombre_equipo;
	 	cout<<"Ingrese el nombre del entrenador"<<endl;
	 	cin>>entrenador;
	 	cout<<"Ingrese el nombre de la region"<<endl;
	 	cin>>region; 	
		cout<<"ingrese el la cantidad de jugadores"<<endl; 	
	    cin>>cant_jug;
	    
	    equipo[i].nombre=nombre_equipo;
	    equipo[i].entrenador=entrenador;
	    equipo[i].region=region;
	    
	    if(cant_jug!=0){		
		    jugador jug[cant_jug];
			for(int j=0;j<cant_jug;j++){
		    	
				cout<<"Ingrese el nombre del jugador "<<j+1<<endl;
	 			cin>>nombre_jugador;
	 			cout<<"Ingrese la posicion"<<endl;
	 			cin>>posic;
	 			cout<<"Ingrese la edad"<<endl;
	 			cin>>edad; 	
				cout<<"Ingrese la cantidad de tarjetas"<<endl;
				cin>>cant_tarj;
				jug[j].nombre=nombre_jugador;
				jug[j].posic=posic;
				jug[j].edad=edad;
				
				if(cant_tarj!=0){
					
					tarjetas tar[cant_tarj];
					
					for(int k=0; k<cant_tarj; k++){
						cout<<"Ingrese el color de la tarjeta "<<k+1<<endl;
	 					cin>>color;
	 					cout<<"Ingrese la causa de la tarjeta"<<endl;
	 					cin>>causa; 	
						cout<<"Ingrese separado de un enter el dia, mes , año de la tarjeta"<<endl;
						cin>>dia,cin>>mes,cin>>year;
						
						tar[k].color=color;
						tar[k].causa=causa;
						tar[k].dia=dia;
						tar[k].mes=dia;
						tar[k].year=year;
						jug[j].t.insertar_pos(k,tar[k]);
					}
					
				}
			 		equipo[i].j.insertar_pos(j, jug[j]);
				}
			
			}
			equipos.insertar_pos(i,equipo[i]);
		}
	}
	
	

 	
}

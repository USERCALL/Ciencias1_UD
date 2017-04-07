#include <iostream>
#include <lista.h>
/* run this program using the console pauser or add your own getch, system("pause") or input loop */
using namespace std;

struct Estudiante{
	int codigo;
	string nombre;
};



int main(int argc, char** argv) {
/*	
	lista<int> milista;
	  lista<float> milista2;
	 
	milista.insertar_elemento(2);
	milista.insertar_elemento(3);
	milista.insertar_elemento(4);
	milista.insertar_elemento(5);
	milista.imprimir();
	milista.buscar_elemento(2);
	milista.borrar_elemento(2);
	milista.imprimir();
	milista.modificar_elemento(2,8);
	milista.imprimir();

	
	
	for(int i=1;i<=4;i++){
		milista.insertar_elemento(i*8);
	}
	milista.imprimir();
	
	milista.modificar_elemento(2,12);
	milista.imprimir();
	milista.borrar_elemento(3);
	milista.imprimir();
	for(int j=1; j<4; j++){
		milista.buscar_elemento(j);		
	}


  cout<<"--------------------------------------------------------------------"<<endl;
  

  
  	for(float i=1;i<=4;i++){
		milista2.insertar_elemento(i/8);
	}
	milista2.imprimir();
	
	milista2.modificar_elemento(1,3.5);
	milista2.imprimir();
	milista2.borrar_elemento(2);
	milista2.imprimir();
	for(int j=1; j<4; j++){
		milista2.buscar_elemento(j);		
	}
*/
	Estudiante aux; 
	lista<Estudiante> est;
	for(int i=1; i<=3; i++){
		cout<<"codigo: "<<endl;
		cin>>aux.codigo;
		cout<<"nombre: "<<endl;
		cin>>aux.nombre;
		est.insertar_elemento(aux);
	}
	//est.imprimir();
//	est.buscar_elemento(1);
	Estudiante estu;
//	estu = est.buscar_elemento(1);
//	cout<<"codigo"<<estu.codigo<<endl;
	
	for(int j=1;  j<4; j++){
		estu= est.buscar_elemento(j);
		cout<<"codigo: "<<j<<" "<<estu.codigo<<endl;
	}
	return 0;
}

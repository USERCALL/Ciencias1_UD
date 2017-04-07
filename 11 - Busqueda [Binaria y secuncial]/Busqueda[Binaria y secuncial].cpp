#include <iostream>
#include <stdlib.h>

using namespace std;

int BusquedaSecuencial(int arr[],int t,int num){
	int j;
	for (j=0;j<t;j++){
		if (arr[j]==num){
			return j;
		}
	}
}

int BusquedaBinaria(int arre[],int ta, int nu){
	int in=0;
	int fi=ta-1;
	int med = fi/2;
	while (arre[fi]!=nu){
		if(arre[in]==nu){
			fi=in;
		}else{
			if (arre[med]==nu){
                fi=med;
            }else{
                  if (arre[med]>nu){
                      fi=med;
                  }
                  if (arre[med]<nu){
                      in=med;
                  }
            med=((fi-in)/2)+in;
            }
		}
	}
	return fi;
}

int main(int argc, char*argv[]){
	//Llenar arreglo
	char a;
	int tam;
	//int ini, fin, t;
	cout<<"Ingrese el tamaño del arreglo:"<<endl;
	cin>>tam;
    int arreglo[tam];
	int i;
	for (i=0;i<tam;i++){
		arreglo[i]=i;
	}
	//Guardar posicion 500
	int var=arreglo[498000];
	//ini=clock();
	//Escribir "Inicio del algoritmo de fuerza bputa"
	cout<<"Inicio del algoritmo de fuerza bruta"<<endl;
	system("pause");
	//Busqueda secuencial
	cout<<"La posicion del numero es:"<<BusquedaSecuencial(arreglo,tam,var)<<endl;
	//Escribir "Fin del algoritmo de fuerza bruta"
	cout<<"Fin del algoritmo de fuerza bruta"<<endl;
	//"e inicio del algoritmo busqueda binaria"
	cout<<"Inicio del algoritmo de busqueda binaria"<<endl;
	system("pause");
	//Buscqueda Binaria
	cout<<"La posicion del numero es:"<<BusquedaBinaria(arreglo,tam,var)<<endl;
	//Escribir "Fin del algoritmo de busqueda binaria"
	cout<<"Fin del algoritmo de busqueda binaria"<<endl;
	//fin=clock();
    //t=fin-ini;
    //cout<<"El tiempo de ejecucion del proceso 'X' es de.."<<t<<endl;
	system("pause");
}

#include <iostream>
#include <conio.h>
#include <windows.h>
using namespace std; 
/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void busqueda(int arregloEntero[],int n,int dato){
	int inf,sup,mitad,i;
	char band='F';
	
    inf=0;
	sup=n;
	i=0;
	
	while((inf<=sup)&&(i<n)){
		mitad = (inf+sup)/2;
		//cout<<"la mitad es: "<<mitad<<endl;
		if(arregloEntero[mitad] == dato){
			band='V';
			break;
		}
		if(arregloEntero[mitad]>dato){
			sup = mitad;
			mitad = (inf+sup)/2;
		}
		if(arregloEntero[mitad]<dato){
			inf = mitad;
			mitad = (inf+sup)/2;
		}
		i++;
	}
	
	if(band == 'V'){
		cout<<"El numero se encontro en la posicion: "<<mitad<<" y es el numero: "<<arregloEntero[mitad]<<endl;
	}
	else{
		cout<<"El numero NO se encontro";
	}
		
}



double performancecounter_diff(LARGE_INTEGER *a, LARGE_INTEGER *b)
{
  LARGE_INTEGER freq;
  QueryPerformanceFrequency(&freq);
  return (double)(a->QuadPart - b->QuadPart) / (double)freq.QuadPart;
}



int main(int argc, char** argv) {
	
	LARGE_INTEGER t_ini, t_fin;
	double secs;
	
	int n,dato;
	
	printf("digite el tamaño: ","\n");
	cin>>n;
    
	int arregloEntero[n];
	for(int i=0; i<n; i++){
	 arregloEntero[i]=1+i;
	 cout<<arregloEntero[i]<<" ";
	}
	
	cout<<endl;
	cout<<"ingrese el dato buscado"<<endl;
	cin>>dato;
    
	QueryPerformanceCounter(&t_ini);
  	busqueda(arregloEntero,n,dato); 	
	QueryPerformanceCounter(&t_fin);
	
	cout<<endl;
	
	secs = performancecounter_diff(&t_fin, &t_ini);
    printf("%.16g milliseconds\n", secs * 1000.0);
	
	//getch();
	return 0;
}




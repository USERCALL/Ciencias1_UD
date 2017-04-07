/*******************************************************************************
Algoritmo de Arboles Narios tomado de estructuras de datos Alfrd V Aho
Representacion de <<Hijo mas a la izquierda hermno derecha>>
*******************************************************************************/

//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058

#include <iostream>
#include <fstream> //archivos
#include <iomanip> 
#include <iostream>
#include <windows.h> //limpiar
#include <string>
#include "lista.h" 

using namespace std;



struct vertice {vertice *hijo_izq=NULL, *hemano_der=NULL, *padre=NULL; char info;};
typedef vertice nodoCelda;

struct espacio_celda {int hijo_izq, hermano_der, info;};
typedef espacio_celda celda;

//dode se almacena la info 
celda *arr;

void cargarArchivo(ifstream &in , celda *arr , int &root);// paso la variable para que no se duplique

int crea(char info, int a1, int a2);

/*
nodoCelda enlazar(char info, nodoCelda *hijo_mas_izq, *hermano_der){
	
	nodoCelda *subArbol;
	subArbol = new nodoCelda;
	subArbol->info = info; 
	subArbol->hijo_izq = hijo_mas_izq;
	subArbol->hemano_der = hermano_der;
	//subArbol>padre = padre;
	return *subArbol;
} 

*/	
	

celda retornarCelda(int index){
	return arr[index];
}
	
nodoCelda convertir(int index){
	
	celda temp = retornarCelda(index);
	nodoCelda *newNodo;
		
	
	while(temp.hijo_izq != 0){
		if(temp.hijo_izq==0){
			newNodo = new nodoCelda;
			return NULL;
		}else{
			newNodo->hijo_izq = convertir(temp.hijo_izq);
			newNodo->info = temp.info;
			newNodo->hemano_der = convertir(temp.hermano_der);
			return newNodo;
		}
}
	
	
	

int main (){
	
	ifstream archEntrada("arbol.txt", ios::in);
	ofstream archSalida("Generado.txt",ios::out|ios::trunc);	
	
	
	int raiz=0;
	
//	Lista<int> celdas;
	
	char select_menu; 

 	do{
		cout<<"------"<<endl;
		
		cout<<"Generar (A)utomatico"<<endl;
		cout<<"Generar (M)anual"<<endl;
		cout<<"(C)argar Archivo"<<endl;
		cout<<"(S)alir"<<endl;
		cout<<"------"<<endl;
		cout<<"Selecciona la opcion : ";cin>>select_menu;
	    
	    switch(select_menu){
	 	 	
	 	 	
	 	 	case 'A':	
	 		case 'a': 
	 					

					break;
	 	 	
			case 'M':	
			case 'm': 
	 					

					break;
	 	 	
	     	case 'C':	
	 		case 'c': 
	 					
						cout<<"Cargado el archivo"<<endl;
	 					cargarArchivo(archEntrada, arr, raiz);
					
					break;
	 				 	
	     	case 'S':
	 		case 's':	cout<<"---------------------------------------"<<endl;
		                cout<<"Gracias por usar la aplicacion"<<endl;
	                  	cout<<"---------------------------------------"<<endl;
	 		        
					 
					 break;
	 	
	      default : cout<< "\n ERROR  Dato invalido \n" <<endl;}
	 }while(select_menu!='s' &&  select_menu!='S');
		 
	system("pause");
	return 1;}

void cargarArchivo(ifstream &in, celda *arr, int &root){
	
	if (!in.good()){
		cerr << "No se pudo abrir el archivo trios" << endl;
		exit(1);}
		
	int leng ; //guarda longitud arreglo
	int raiz ;
	
	in >> leng;
	in >> raiz;
	
	cout << "Raiz :"<< raiz<<endl; 
	cout << "Longitud "	<<leng<<endl;
	
	int index, leftSon, rightBrother;
	char info; 
	
	arr = new celda[leng];
	
	cout<<"leyendo archivo  index \t leftSon\t info \t rightBrother"<<endl;	
	// lectura del archivo y creaciòn del arreglo   
	while(!in.eof()){
	
		in >> index;
		in >> leftSon;
		arr[index].hijo_izq = leftSon;
		in >> info;
		arr[index].info = info;
		in >> rightBrother;
		arr[index].hermano_der;
			cout<<"leyendo archivo "<< index <<"\t"<< leftSon<<"\t"<< info <<"\t"<< rightBrother<<endl;	
		}
	in.close();
	
	/*
	char tempInfo;
	
 	nodoCelda *raiz, *tempRaiz, *tempHijo, *tempHermano;
 	
 	tempInfo = arr[arr[raiz].hijo_izq].info
 	
 	
	
	tempRaiz = enlazar(tempInfo, arr[arr[raiz].hijo_izq].hijo_izq,
						 arr[arr[raiz].hijo_izq].hermano_der);
	
	
 	raiz =	enlazar(arr[raiz].info, tempRaiz, -1, -1);
    	
	*/
}

// devulve indice donde esta el arbol
int inserta(char info, int a1, int a2){
/*
	// a1 hijo a2 herm	
	
	int temp; // indice celda donde se inserta el nodo 
	int disp // guarda el primer indice de la raiz disponible -> sig insercion
	
	if(disp=)
	temp = disp;
	disp = celda[disp].hermano_der;
	celda[temp].hijo_izq = a1;
	celda[temp].info = info;
	celda[temp].hermano_der = 0;
	celda[a1].hijo_izq = a2;
	celda[a2].hermano_der = 0; // corregir 
	return temp;}
*/
}


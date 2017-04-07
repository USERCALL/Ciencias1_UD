/*******************************************************************************
Menu de Aplicacion " con caracter se ve mejor, pero puede incurir en datos
con confucsion del codigo asci"
*******************************************************************************/

//Diego Hernandez -> 20141020271

#include<iostream>
#include <windows.h>
#include<string>

using namespace std;

int main (){
	char select_menu; 

 	do{
		cout<<"------"<<endl;
		cout<<"(C)olocar"<<endl;
		cout<<"(S)alir"<<endl;
		cout<<"------"<<endl;
		cout<<"Selecciona la opcion : ";cin>>select_menu;
	    
	    switch(select_menu){
	 	 	
	     	case 'C':	
	 		case 'c': 
	 					cout<<"Selecciono la c"<<endl;
	 					cout<<"Esperando a limpriar"<<endl;
	 					
						Sleep(3000);
 		            	system("cls");
	 					
					break;
	 				 	
	     	case 'S':
	 		case 's':	cout<<"---------------------------------------"<<endl;
		                cout<<"Gracias por usar la aplicacion"<<endl;
	                  	cout<<"---------------------------------------"<<endl;
	 		        
					 
					 break;
	 	
	      default : cout<< "\n ERROR  Dato invalido \n" <<endl;}
	 }while(select_menu!='s' &&  select_menu!='S');
		 
	system("pause");
	return 1;   
}


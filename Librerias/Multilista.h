
#include <cstdlib>
#include <iostream>

using namespace std;

int final;

struct Estud{
       string nombre, carrera, hobby;
       int edad;
       int signombre, sigcarrera, sighobby, sigedad;
       };

struct Cabezas{
       string nombre;
       int pos_primero;
       };

Estud listaDatos[16];
Cabezas listaCabezas[4];

class Multilista{
     public: Multilista(){final = 0;listaCabezas[0].nombre = "nombre";
                 listaCabezas[1].nombre = "carrera";
                 listaCabezas[2].nombre = "hobby";
                 listaCabezas[3].nombre = "edad";}
             bool vacia();
             bool llena();
             void obtenerLista(string Var);
             void enlazarAscendente(string Var);
             void enlazarFinal(string Var);
             void enlazarDescendente(string Var);
             void insertar(string nombre, string carrera, string hobby, int edad);
             void primerE(string Var);
             void ultimoE(string Var);
             void sigM (int pos, string Var);
             void antM (int pos, string Var);
             void buscar (int pos, string Var); 
             void eliminar (int pos, string Var);      
};


bool vacia(){
    if (final == 0){
        return true;
    }
    return false; 
}

bool llena(){
    if (final == 15){
        return true;
    }
    return false; 
}

void obtenerLista(string Var){
     int i = 0;
     int k;
     while(listaCabezas[i].nombre != Var){
          i++;
     }
     k = listaCabezas[i].pos_primero;
     while (k!=0){
          if (Var == "nombre"){
              cout<<"Dato : "<<listaDatos[k].nombre<<endl;
              k = (listaDatos[k]).signombre;
          }else if (Var == "carrera"){
              cout<<"Dato : "<<listaDatos[k].carrera<<endl;
              k = (listaDatos[k]).sigcarrera;
          }else if (Var == "hobby"){
              cout<<"Dato : "<<listaDatos[k].hobby<<endl;
              k = (listaDatos[k]).sighobby;
          }else if (Var == "edad"){
              cout<<"Dato : "<<listaDatos[k].edad<<endl;
              k = (listaDatos[k]).sigedad;
          }
     }
}

void enlazarAscendente(string Var){
     int i = 0;
     int k;
     while(listaCabezas[i].nombre != Var){
          i++;
     }
     k = listaCabezas[i].pos_primero;
     if (final != 1){
         if ((listaDatos[k].nombre) > (listaDatos[final].nombre)){
         	listaCabezas[i].pos_primero = final;
         	listaDatos[final].signombre = k;
		 }else{
		 	while ((listaDatos[k].nombre) < (listaDatos[final].nombre) && k!=0){
		 		listaDatos[final].signombre = listaDatos[k].signombre;
		 		listaDatos[k].signombre = final;
		 		k = listaDatos[final].signombre;
			 }
		 }
     }else{
         listaCabezas[i].pos_primero = 1;
     }
}

void enlazarFinal(string Var){
     int i = 0;
     int k;
     while(listaCabezas[i].nombre != Var){
          i++;
     }
     k = listaCabezas[i].pos_primero;
     if (final != 1){
         if (Var == "carrera"){
            while (listaDatos[k].sigcarrera!=0){
              k = listaDatos[k].sigcarrera;
            }
            listaDatos[k].sigcarrera = final;
         }else if (Var == "hobby"){
            while (listaDatos[k].sighobby!=0){
              k = listaDatos[k].sighobby;
            }
            listaDatos[k].sighobby = final;
         }
     }else{
         listaCabezas[i].pos_primero = 1;
     }
}

void enlazarDescendente(string Var){
     int i = 0;
     int k;
     while(listaCabezas[i].nombre != Var){
          i++;
     }
     k = listaCabezas[i].pos_primero;
     if (final != 1){
         if (listaDatos[k].edad < listaDatos[final].edad){
         	listaCabezas[i].pos_primero = final;
         	listaDatos[final].sigedad = k;
		 }else{
		 	while (listaDatos[k].edad > listaDatos[final].edad and k!=0){
		 		listaDatos[final].sigedad = listaDatos[k].sigedad;
		 		listaDatos[k].sigedad = final;
		 		k = listaDatos[final].sigedad;
			 }
		 }
     }else{
         listaCabezas[i].pos_primero = 1;
     }
}

void insertar(string nombre, string carrera, string hobby, int edad){
     if (!llena()){
         final++;
         listaDatos[final].nombre = nombre;
         listaDatos[final].carrera = carrera; 
         listaDatos[final].hobby = hobby;
         listaDatos[final].edad = edad; 
         listaDatos[final].signombre = 0;
         listaDatos[final].sigcarrera = 0; 
         listaDatos[final].sighobby = 0;
         listaDatos[final].sigedad = 0; 
     }
     enlazarAscendente("nombre");
     enlazarFinal("carrera");
     enlazarFinal("hobby");
     enlazarDescendente("edad");
}

void primerE(string Var){
	int i = 0;
	int k;
	while(listaCabezas[i].nombre != Var){
          i++;
    }
    k = listaCabezas[i].pos_primero;
    cout<<"Nombre: "<<listaDatos[k].nombre<<endl;
    cout<<"Carrera: "<<listaDatos[k].carrera<<endl;
    cout<<"Hobby: "<<listaDatos[k].hobby<<endl;
    cout<<"Edad: "<<listaDatos[k].edad<<endl;
}

void ultimoE(string Var){
	int i = 0;
	int k;
	while(listaCabezas[i].nombre != Var){
          i++;
    }
    k = listaCabezas[i].pos_primero;
    if (final!=1){
    	if (Var == "nombre"){
         	while(listaDatos[k].signombre != 0){
        		k = listaDatos[k].signombre;
    		}
       }else if (Var == "carrera"){
        	while(listaDatos[k].sigcarrera != 0){
         		k = listaDatos[k].sigcarrera;
    		}
       }else if (Var == "hobby"){
        	while(listaDatos[k].sighobby != 0){
        		k = listaDatos[k].sighobby;
	    	}
        }else if (Var == "edad"){
        	while(listaDatos[k].sigedad != 0){
        		k = listaDatos[k].sigedad;
		   }
       }
	}
    cout<<"Nombre: "<<listaDatos[k].nombre<<endl;
    cout<<"Carrera: "<<listaDatos[k].carrera<<endl;
    cout<<"Hobby: "<<listaDatos[k].hobby<<endl;
    cout<<"Edad: "<<listaDatos[k].edad<<endl;
}

void sigM (int pos, string Var){
	int k , i = 0;
	while(listaCabezas[i].nombre != Var){
          i++;
    }
    k = listaCabezas[i].pos_primero;
    if (Var == "nombre"){
    	for (i=1;i<=pos;i++){
    		k = listaDatos[k].signombre;
		}
	}else if (Var == "carrera"){
		for (i=1;i<=pos;i++){
    		k = listaDatos[k].sigcarrera;
		}
	}else if (Var == "hobby"){
		for (i=1;i<=pos;i++){
    		k = listaDatos[k].sighobby;
		}
    }else if (Var == "edad"){
    	for (i=1;i<=pos;i++){
    		k = listaDatos[k].sigedad;
		}
    }	
	cout<<"Nombre: "<<listaDatos[k].nombre<<endl;
    cout<<"Carrera: "<<listaDatos[k].carrera<<endl;
    cout<<"Hobby: "<<listaDatos[k].hobby<<endl;
    cout<<"Edad: "<<listaDatos[k].edad<<endl;
}


void antM (int pos, string Var){
	int k , i = 0;
	while(listaCabezas[i].nombre != Var){
          i++;
    }
    k = listaCabezas[i].pos_primero;
    if (Var == "nombre"){
    	for (i=2;i<pos;i++){
    		k = listaDatos[k].signombre;
		}
	}else if (Var == "carrera"){
		for (i=2;i<pos;i++){
    		k = listaDatos[k].sigcarrera;
		}
	}else if (Var == "hobby"){
		for (i=2;i<pos;i++){
    		k = listaDatos[k].sighobby;
		}
    }else if (Var == "edad"){
    	for (i=2;i<pos;i++){
    		k = listaDatos[k].sigedad;
		}
    }	
	cout<<"Nombre: "<<listaDatos[k].nombre<<endl;
    cout<<"Carrera: "<<listaDatos[k].carrera<<endl;
    cout<<"Hobby: "<<listaDatos[k].hobby<<endl;
    cout<<"Edad: "<<listaDatos[k].edad<<endl;
}

void buscar (int pos, string Var){
	int k , i = 0;
	while(listaCabezas[i].nombre != Var){
          i++;
    }
    k = listaCabezas[i].pos_primero;
    if (Var == "nombre"){
    	for (i=1;i<pos;i++){
    		k = listaDatos[k].signombre;
		}
	}else if (Var == "carrera"){
		for (i=1;i<pos;i++){
    		k = listaDatos[k].sigcarrera;
		}
	}else if (Var == "hobby"){
		for (i=1;i<pos;i++){
    		k = listaDatos[k].sighobby;
		}
    }else if (Var == "edad"){
    	for (i=1;i<pos;i++){
    		k = listaDatos[k].sigedad;
		}
    }	
	cout<<"Nombre: "<<listaDatos[k].nombre<<endl;
    cout<<"Carrera: "<<listaDatos[k].carrera<<endl;
    cout<<"Hobby: "<<listaDatos[k].hobby<<endl;
    cout<<"Edad: "<<listaDatos[k].edad<<endl;
}

void eliminar (int pos, string Var){
	int k , j , i = 0;
	while(listaCabezas[i].nombre != Var){
          i++;
    }
    k = listaCabezas[i].pos_primero;
    if (Var == "nombre"){
    	for (i=1;i<pos;i++){
    		k = listaDatos[k].signombre;
		}
	}else if (Var == "carrera"){
		for (i=1;i<pos;i++){
    		k = listaDatos[k].sigcarrera;
		}
	}else if (Var == "hobby"){
		for (i=1;i<pos;i++){
    		k = listaDatos[k].sighobby;
		}
    }else if (Var == "edad"){
    	for (i=1;i<pos;i++){
    		k = listaDatos[k].sigedad;
		}
    }
    
    j = listaCabezas[0].pos_primero;
	while (listaDatos[j].signombre != k){
          j = listaDatos[j].signombre;
    }
    listaDatos[j].signombre = listaDatos[k].signombre;
    j = listaCabezas[1].pos_primero;
	while (listaDatos[j].sigcarrera != k){
          j = listaDatos[j].sigcarrera;
    }
    listaDatos[j].sigcarrera = listaDatos[k].sigcarrera;
    j = listaCabezas[2].pos_primero;
	while (listaDatos[j].sighobby != k){
          j = listaDatos[j].sighobby;
    }
    listaDatos[j].sighobby = listaDatos[k].sighobby;
    j = listaCabezas[3].pos_primero;
	while (listaDatos[j].sigedad != k){
          j = listaDatos[j].sigedad;
    }
    listaDatos[j].sigedad = listaDatos[k].sigedad;
    
   	cout<<"Nombre: "<<listaDatos[k].nombre<<endl;
    cout<<"Carrera: "<<listaDatos[k].carrera<<endl;
    cout<<"Hobby: "<<listaDatos[k].hobby<<endl;
    cout<<"Edad: "<<listaDatos[k].edad<<endl;
    
    while(k != final){
            listaDatos[k].nombre = listaDatos[k+1].nombre;
            listaDatos[k].carrera = listaDatos[k+1].carrera;
            listaDatos[k].hobby = listaDatos[k+1].hobby;
            listaDatos[k].edad = listaDatos[k+1].edad;
            listaDatos[k].signombre = listaDatos[k+1].signombre;
            listaDatos[k].sigcarrera = listaDatos[k+1].sigcarrera;
            listaDatos[k].sighobby = listaDatos[k+1].sighobby;
            listaDatos[k].sigedad = listaDatos[k+1].sigedad;
    }
    listaDatos[final].nombre = "";
    listaDatos[final].carrera = "";
    listaDatos[final].hobby = "";
    listaDatos[final].edad = 0;
    listaDatos[final].signombre = 0;
    listaDatos[final].sigcarrera = 0;
    listaDatos[final].sighobby = 0;
    listaDatos[final].sigedad = 0;
    final--;
}

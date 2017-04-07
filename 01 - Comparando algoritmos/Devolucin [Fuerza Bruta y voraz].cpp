/*******************************************************************************
"Programa para dar vueltas de dinero en forma por fuerza brura o voraz"
*******************************************************************************/

#include <cstdlib>
#include <iostream>

using namespace std;

int arreglo[6]={0,0,0,0,0,0};

void BusquedaSecuencial(int mone){
    int m=mone;
    arreglo[5]=m;
    while(m-5>=0){
       arreglo[5]-=5;
       arreglo[4]+=1;
       m-=5;
    }
    m=mone;
    while(m-10>=0){
       arreglo[4]-=2;
       arreglo[3]+=1;
       m-=10;
    }
    m=mone;
    while(m-20>=0){
       arreglo[3]-=2;
       arreglo[2]+=1;
       m-=20;
    }
    m=mone;
    while(m-50>=0){
       if(arreglo[3]!=0){
          arreglo[3]-=1;
          arreglo[2]-=2;
          arreglo[1]+=1;
          m-=50;
       }else{
          arreglo[3]+=1;
          arreglo[2]-=3;
          arreglo[1]+=1;
          m-=50;
       }
    }
    m=mone;
    while(m-100>=0){
       arreglo[1]-=2;
       arreglo[0]+=1;
       m-=100;
    }
}

void BusquedaVoraz(int mon){
     while(mon!=0){
          if(mon>=100){
             mon=mon-100;
             arreglo[0]+=1;
          }else{
             if(mon>=50){
               mon=mon-50;
               arreglo[1]+=1;
             }else{
               if(mon>=20){
                  mon=mon-20;
                  arreglo[2]+=1;
                }else{
                  if(mon>=10){
                     mon=mon-10;
                     arreglo[3]+=1;
                  }else{
                     if(mon>=5){
                       mon=mon-5;
                       arreglo[4]+=1;
                     }else{
                        if(mon>=1){
                           mon=mon-1;
                           arreglo[5]+=1;
                        }
                     }
                  }
                }
              }
          }
     }
}

int main(int argc, char *argv[])
{
    cout<< "Programa para dar vueltas de dinero en forma por fuerza brura o voraz"<<endl;
    //Moneda Para Cambiar
    int moneda=98563;
    int i;
    //int ini, fin, t;
    cout<<"Ingrese el cambio que desea:"<<endl;
	cin>>moneda;
	//ini=clock();
    //Escribir "Inicio del algoritmo de fuerza bruta";
	cout<<"Inicio del algoritmo de fuerza bruta"<<endl;
	system("PAUSE");
	//Busqueda secuencial
	BusquedaSecuencial(moneda);
	cout<<"El cambio es:"<<endl;
	cout<<"100:"<<arreglo[0]<<endl;
	cout<<"50:"<<arreglo[1]<<endl;
	cout<<"20:"<<arreglo[2]<<endl;
	cout<<"10:"<<arreglo[3]<<endl;
	cout<<"5:"<<arreglo[4]<<endl;
	cout<<"1:"<<arreglo[5]<<endl;
    //Escribir "Fin del algoritmo de fuerza bruta"
	cout<<"Fin del algoritmo de fuerza bruta"<<endl;
	arreglo[0]=0;
	arreglo[1]=0;
	arreglo[2]=0;
	arreglo[3]=0;
	arreglo[4]=0;
	arreglo[5]=0;
	//"e inicio del algoritmo busqueda voraz"
	cout<<"Inicio del algoritmo de busqueda voraz"<<endl;
	system("PAUSE");
	//Buscqueda Voraz
	BusquedaVoraz(moneda);
	cout<<"El cambio es:"<<endl;
	cout<<"100:"<<arreglo[0]<<endl;
	cout<<"50:"<<arreglo[1]<<endl;
	cout<<"20:"<<arreglo[2]<<endl;
	cout<<"10:"<<arreglo[3]<<endl;
	cout<<"5:"<<arreglo[4]<<endl;
	cout<<"1:"<<arreglo[5]<<endl;
	//Escribir "Fin del algoritmo de busqueda binaria"
	cout<<"Fin del algoritmo de busqueda binaria"<<endl;
	//fin=clock();
    //t=fin-ini;
    //cout<<"El tiempo de ejecucion del proceso 'X' es de.."<<t<<endl;
    system("PAUSE");
}

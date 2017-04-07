/*  Arbol rojo negro
    Compilador: Borland c++ 5.02
    Programó: Pedro Cardoso Rodriguez correo_e: cardp_2004@yahoo.com.mx
    Zacatecas, Mexico. Octubre del 2006
*/
#include <stdio.h>
#include <conio.h>
#include <string.h>

using namespace std;
 // variables globales
struct nodo{ // los nodos del arbol
  int llave;
  char color; // donde r es rojo y n es negro
  struct nodo *izquierdo;
  struct nodo *derecho;
  struct nodo *padre;
  char cadena[32];
};
nodo *inicio; // el inicio del arbol
 // funciones a utilizar
void insercion(int key, char cad[32]); // para insertar un numero en el arbol
void solucionarRojoRojo(nodo *node, int h); // para solucionar un hijo rojo en un nodo rojo
nodo *buscar(int key); // para buscar un numero en el arbolito
void ver(nodo *node, int esp, int h); // ver el arbol
int menus(int n_opciones, int x, int y); // para manejar menu con las teclas de las flechas
void liberar(nodo *node); // para liberar la memoria cuando salir del programa

 main(void){
  int opcion, numero;
  nodo *ayudante;
  char cadenalocal[32];
  inicio=NULL;
  //textbackground(15);
  do{
    clrscr(); fflush(stdin); textcolor(16); cprintf("    Arbol rojo negro\n\r");
    cprintf("  Insertar un numero\n\r  Buscar un numero\n\r  Ver el arbol\n\r  Terminar");
    opcion=menus(4, 2, 2);
    switch(opcion){
     case 1:
       gotoxy(4,6), cprintf("teclea el numero a insertar "); scanf("%d",&numero);
       gotoxy(4,7), cprintf("teclea la cadena a insertar "); scanf("%s",cadenalocal);
       insercion(numero,cadenalocal);
       gotoxy(6,9), cprintf("presiona una tecla para continuar...");
       break;
     case 2:
       gotoxy(4,6), cprintf("teclea el numero a buscar "); scanf("%d",&numero);
       ayudante=buscar(numero);
       if(ayudante)
         cprintf(" Se encontro ese numero su cadena es:\n\r  %s",ayudante->cadena);
       else cprintf(" No se encontro ese numero en el arbol");
       cprintf("\n\r  presiona una tecla para continuar...");
       break;
     case 3:
       clrscr(); ver(inicio, 0, 0); cprintf("\n\n\r Presiona una tecla para continuar...");
       break;
    }
    if(opcion!=4) getch();
  }while(opcion!=4);
  liberar(inicio);
}

void insercion(int key, char cad[32]){
  int ladohijo;
  nodo *hijo;
  nodo *ayudante;
  int bandera;
  if(!inicio){ // el arbol esta vacio cargando como raiz
    inicio = new nodo;
    inicio->llave=key; strcpy(inicio->cadena,cad); inicio->padre=NULL;
    inicio->izquierdo=NULL; inicio->derecho=NULL; inicio->color='n';
  }
  else{ // el arbol no esta vacio buscando su lugar
    hijo = new nodo; hijo->llave=key; strcpy(hijo->cadena,cad);
    hijo->padre=NULL; hijo->izquierdo=NULL; hijo->derecho=NULL;
    hijo->color='r'; ayudante=inicio;
    do{
      hijo->padre=ayudante, bandera=1;
      if(key<ayudante->llave){
        if(ayudante->izquierdo) ayudante=ayudante->izquierdo;
        else ayudante->izquierdo=hijo, bandera=0, ladohijo=1;
      }
      else{
        if(ayudante->derecho) ayudante=ayudante->derecho;
        else ayudante->derecho=hijo, bandera=0, ladohijo=2;
      }
    }while(bandera==1);
    if(ayudante->color=='r') solucionarRojoRojo(ayudante, ladohijo);
  }
}

void solucionarRojoRojo(nodo *node, int h){
  int ladohijo;
  nodo *abuelo; // en node traemos al padre, en h 1 si el hijo rojo es el izquierdo 2 si no
  nodo *tio;
  nodo *ayudante;
  abuelo=node->padre;
  if(abuelo->izquierdo && abuelo->derecho){
    if(node==abuelo->izquierdo) tio=abuelo->derecho;
    else tio=abuelo->izquierdo;
// los siguientes casos son la codificacion de los apoyos obtenidos en un documento descargado de:
//        http://ingenieria.reduaz.mx/~besolis
    if(tio->color=='r'){ // caso uno y dos
      tio->color='n'; node->color='n';
      if(abuelo!=inicio) abuelo->color='r';
      if(abuelo->padre){
        ayudante=abuelo->padre;
        if(ayudante->izquierdo==abuelo) ladohijo=1;
        else ladohijo=2;
        if(ayudante->color=='r') solucionarRojoRojo(ayudante, ladohijo);
      }
      return;
    }
  }
  if(h==1 && abuelo->izquierdo==node){ // caso tres
    node->color='n', abuelo->color='r';
    ayudante=node->derecho, node->derecho=abuelo, node->padre=abuelo->padre;
    abuelo->padre=node, abuelo->izquierdo=ayudante;
    if(ayudante) ayudante->padre=abuelo;
    if(node->padre){
      ayudante=node->padre;
      if(ayudante->izquierdo==node->derecho) ayudante->izquierdo=node;
      else ayudante->derecho=node;
    }
    else inicio=node;
  }
  else if(h==2 && abuelo->derecho==node){ // caso cuatro
    node->color='n', abuelo->color='r';
    ayudante=node->izquierdo, node->izquierdo=abuelo, node->padre=abuelo->padre;
    abuelo->padre=node, abuelo->derecho=ayudante;
    if(ayudante) ayudante->padre=abuelo;
    if(node->padre){
      ayudante=node->padre;
      if(ayudante->izquierdo==node->izquierdo) ayudante->izquierdo=node;
      else ayudante->derecho=node;
    }
    else inicio=node;
  }
  else if(h==2 && abuelo->izquierdo==node){ // caso cinco
    tio=node->derecho, ayudante=tio->izquierdo, abuelo->izquierdo=tio;
    tio->padre=abuelo, tio->izquierdo=node, node->padre=tio;
    node->derecho=ayudante;
    if(ayudante) ayudante->padre=node;
    solucionarRojoRojo(tio, 1);
  }
  else if(h==1 && abuelo->derecho==node){ // caso seis
    tio=node->izquierdo, ayudante=tio->derecho, abuelo->derecho=tio;
    tio->padre=abuelo, tio->derecho=node, node->padre=tio;
    node->izquierdo=ayudante;
    if(ayudante) ayudante->padre=node;
    solucionarRojoRojo(tio, 2);
  }
}

nodo *buscar(int key){
  nodo *ayudante;
  ayudante=inicio;
  if(!ayudante) return NULL;
  do{
    if(key==ayudante->llave) return ayudante;
    else if(key<ayudante->llave) ayudante=ayudante->izquierdo;
    else if(key>ayudante->llave) ayudante=ayudante->derecho;
  }while(ayudante);
  return NULL;
}

void ver(nodo *node, int esp, int h){
  int conter=-1;
  char descripcion[15];
  if(!node && node==inicio){
    gotoxy(4,6); cprintf("El arbol esta vacio");
    return;
  }
  textcolor(10); cprintf("\n\r");
  if(node==inicio) strcpy(descripcion,"Raiz");
  else if(h==1) strcpy(descripcion,"Hijo izquierdo");
  else strcpy(descripcion,"Hijo derecho");
  while(++conter<esp) cprintf("%c ",179);
  cprintf("%c ",195);
  if(node){
    if(node->color=='n') textcolor(16);
    else textcolor(12);
  }
  else textcolor(14);
  if(node) cprintf("Llave=%d cadena=%s [%s]",node->llave,node->cadena,descripcion);
  else cprintf("[NULL] [%s]",descripcion);
  if(node && (node->izquierdo || node->derecho)){
    ver(node->izquierdo, esp+1, 1);
    ver(node->derecho, esp+1, 2);
  }
  textcolor(16);
}

int menus(int n_opciones, int x, int y){
  int tecla, tecla2, opc;
  gotoxy(x,y), cprintf("%c",175), opc=1;
  do{
    tecla=getch();
    if(tecla==0){
      tecla2=getch();
      if(tecla2==80){ // abajo
        gotoxy(x,opc+(y-1)), cprintf("%c",32), gotoxy(x,(opc<n_opciones?opc+y:y));
        cprintf("%c",175), opc=(opc<n_opciones?(opc+1):0);
      }
      if(tecla2==72){ // arriba
        gotoxy(x,opc+(y-1)), cprintf("%c",32), gotoxy(x,(opc>1?(opc+(y-2)):(y+n_opciones-1)));
        cprintf("%c",175), opc=(opc>1?(opc-1):n_opciones);
      }
    }
  }while(tecla!=13);
  return opc;
}

void liberar(nodo *node){
  if(node){
    if(node->izquierdo) liberar(node->izquierdo);
    if(node->derecho) liberar(node->derecho);
    delete node;
  }
}

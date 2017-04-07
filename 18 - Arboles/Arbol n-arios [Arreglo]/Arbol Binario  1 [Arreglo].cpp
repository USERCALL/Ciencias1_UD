/*******************************************************************************
Algoritmo de Arboles Narios tomado de estructuras de datos Alfrd V Aho
Representacion de <<Hijo mas a la izquierda hermno derecha>>
*******************************************************************************/

//Diego Hernandez -> 20141020271
// Cristian Rios  -> 20141020058


#include <cstdlib>
#include <iostream>
#include "Colas.h"

using namespace std;

struct Arr {
  int hijoIzq, herDer;
  string info;
};

Arr arbol[25];
Colas<int> col;

int raiz = 0;
int final = 0;

bool vacia() {
  if (final == 0) {
    return true;
  }
  return false;
}

bool llena() {
  if (final == 24) {
    return true;
  }
  return false;
}

void hijos() {
  int pos;
  if (!vacia()) {
    pos = raiz;
    while (pos != 0) {
      if (arbol[pos].hijoIzq != 0) {
        pos = arbol[pos].hijoIzq;
        col.put(pos);
        pos = 0;
      }
    }
  }
}

void hermanos() {}

void insertar(string info) {
  if (!vacia()) {
  } else {
    final += 1;
    raiz = final;
  }
  arbol[final].hijoIzq = 0;
  arbol[final].herDer = 0;
  arbol[final].info = info;
}

int main(int argc, char *argv[]) {
  system("PAUSE");
  return EXIT_SUCCESS;
}

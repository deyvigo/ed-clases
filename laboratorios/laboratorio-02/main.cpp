#include <iostream>
#include <cstdlib>
#include <time.h>

struct nodo {
  int dato;
  nodo *sgt;
};

using namespace std;
typedef struct nodo *TpLista;

int generarNumero(int, int);
bool buscarID(int, TpLista);
TpLista crearNodo(TpLista);
void insertarInicio(TpLista &, TpLista);
void insertarFinal(TpLista &, TpLista);
void insertar(TpLista &);
void mostrarListaSimple(TpLista);
void mostrarMayorMenor(TpLista);
float sumaPromedio(TpLista);
int contarLista(TpLista);
void menu(TpLista &);

int main () {
  srand(time(NULL));

  TpLista listaSimple = NULL;
  
  menu(listaSimple);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}


TpLista crearNodo(TpLista ls) {
  TpLista tmp = new (struct nodo);

  int dato;
  dato = generarNumero(-400, 400);
  tmp->dato = dato;

  tmp->sgt = NULL;
  return tmp;
}

void insertarInicio (TpLista &ls, TpLista nodo) {
  TpLista tmp = nodo;

  tmp->sgt = ls;
  ls = tmp;
}

void insertarFinal (TpLista &ls, TpLista nodo) {
  if (ls == NULL) {
    ls = nodo;
    return;
  }
  TpLista tmp = nodo;
  TpLista track = ls;

  while (track->sgt != NULL) {
    track = track->sgt;
  }

  track->sgt = tmp;
}

void insertar (TpLista &ls) {
  TpLista newNodo = crearNodo(ls);

  if (newNodo->dato > 0) {
    insertarFinal(ls, newNodo);
  } else {
    insertarInicio(ls, newNodo);
  }
}

float sumaPromedio (TpLista ls) {
  int suma = 0;

  while (ls != NULL) {
    suma += ls->dato;
    ls = ls->sgt;
  }

  return suma;
}

int contarLista (TpLista ls) {
  int cant = 0;

  while (ls != NULL) {
    cant++;
    ls = ls->sgt;
  }

  return cant;
}

void mostrarListaSimple (TpLista ls) {
  int i = 1;
  if (ls == NULL) {
    cout << "Lista Simplemente Enlazada vacía." << endl;
    return;
  }
  while (ls != NULL) {
    cout << i << ") dato: " << ls->dato << endl;
    i++;
    ls = ls->sgt;
  }
}

void mostrarMayorMenor (TpLista ls) {
  TpLista tmp = ls;
  int i = 1;
  int indexMenor;
  int menor = ls->dato;
  while (tmp != NULL) {
    if (menor > tmp->dato) {
      menor = tmp->dato;
      indexMenor = i;
    }
    i++;
    tmp = tmp->sgt;
  }
  cout << "El elemento menor es: " << menor << " || posicion: " << indexMenor << endl;
  tmp = ls;
  i = 1;
  int indexMayor, mayor = ls->dato;
  while (tmp != NULL) {
    if (mayor < tmp->dato) {
      mayor = tmp->dato;
      indexMayor = i;
    }
    i++;
    tmp = tmp->sgt;
  }
  cout << "El elemento mayor es: " << mayor << " || posicion: " << indexMayor << endl;
}

void menu (TpLista &ls) {
  int opcion, position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Agregar nodo a la lista enlazada.\n2. Opcion 2.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        insertar(ls);
        mostrarListaSimple(ls);
        break;
      case 2:
        mostrarMayorMenor(ls);
        cout << "Tamaño de la lista: " << contarLista(ls) << endl;
        cout << "La suma promedio de los elementos es: " << sumaPromedio(ls) / contarLista(ls) << endl;
        break;
    }
  } while (opcion >= 1 && opcion <= 2);
}


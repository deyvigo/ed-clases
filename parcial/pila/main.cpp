#include <iostream>
#include <cstdlib>
#include <time.h>

struct nodo {
  int id;
  int dato;
  nodo *sgt;
};

using namespace std;
typedef struct nodo *TpLista;

int generarNumero(int, int);
bool buscarID(int, TpLista);
TpLista crearNodo(TpLista);
void push(TpLista &);
void pop(TpLista &);
int contarPila(TpLista);
void mostrarPila(TpLista);
void menu(TpLista &);

int main () {
  srand(time(NULL));

  TpLista pila = NULL;

  menu(pila);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}

bool buscarID (int id, TpLista p) {  
  while (p != NULL) {
    if (p->id == id) return true; 
    p = p->sgt;
  }
  return false;
}

TpLista crearNodo(TpLista p) {
  TpLista tmp = new (struct nodo);

  int id, dato;
  do {
    id = generarNumero(100, 300);
  } while (buscarID(id, p));
  dato = generarNumero(300, 400);
  tmp->dato = dato;
  tmp->id = id;

  tmp->sgt = NULL;
  return tmp;
}

void push(TpLista &p) {
  TpLista tmp = crearNodo(p);

  tmp->sgt = p;
  p = tmp;
}

void pop (TpLista &p) {
  if (p == NULL) {
    cout << "La pila esta vacia." << endl;
    return;
  }
  TpLista tmp = p;
  p = p->sgt;
  delete tmp;
}

int contarPila (TpLista p) {
  int cant = 0;

  while (p != NULL) {
    cant++;
    p = p->sgt;
  }

  return cant;
}

void mostrarPila (TpLista p) {
  if (p == NULL) {
    cout << "Nada para mostrar. (La pila esta vacia)" << endl;
    return;
  }
  int i = 1;
  while (p != NULL) {
    cout << i << ") id: "<< p->id << " || dato: " << p->dato << endl;
    i++;
    p = p->sgt;
  }
}

void menu (TpLista &p) {
  int opcion;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Agregar nodo a la pila.\n2. Eliminar nodo de la pila.\n3. Mostrar pila.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        push(p);
        mostrarPila(p);
        break;
      case 2:
        pop(p);
        mostrarPila(p);
        break;
      case 3:
        mostrarPila(p);
        cout << "Cantidad de nodos de la pila: " << contarPila(p) << endl;
        break;
    }
  } while (opcion >= 1 && opcion <= 3);
}

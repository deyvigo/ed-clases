#include <iostream>

struct nodo {
  int dato;
  nodo *siguiente;
};

using namespace std;
typedef struct nodo *Pila;

// definiciones de funciones
void agregar(Pila &, int);
void mostrar(Pila);
void menu(Pila &);

int main () {
  Pila pila = NULL;
  menu(pila);
  return 0;
}

void agregar (Pila &p, int dato) {
  Pila temp = new(struct nodo);
  temp->dato = dato;
  temp->siguiente = p;
  p = temp;
}

void mostrar (Pila p) {
  int index = 0;
  while (p != NULL) {
    cout << index << ": " << p->dato << endl;
    index++;
    p = p->siguiente;
  }
}

void menu (Pila &p) {
  int opcion = 1;
  int dato;
  do {
    cout << "1. Agregar elementos a la pila. \n2. Mostrar elementos de la pila.\n";
    cin >> opcion;
    switch (opcion) {
      case 1:
        cout << "Ingresar dato: " << endl;
        cin >> dato;
        agregar(p, dato);
        break;
      case 2:
        cout << "----------------------------------------\n";
        mostrar(p);
        cout << "----------------------------------------\n";
        break;
    }
  } while (opcion == 1 || opcion == 2);
}
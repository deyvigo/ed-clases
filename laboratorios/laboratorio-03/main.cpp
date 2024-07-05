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
TpLista crearNodo(TpLista, int);
float sumaPromedio (TpLista ls);
int contarLista (TpLista ls);
void insertarFinal (TpLista &);
void insertarImpar (TpLista &ls);
void mostrarListaSimple (TpLista);
int buscarMenor (TpLista);
void eliminarDato(TpLista &, int);
void menu (TpLista &ls);

int main () {
  srand(time(NULL));

  TpLista listaSimple = NULL;
  
  menu(listaSimple);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}

TpLista crearNodo(TpLista ls, int dato) {
  TpLista tmp = new (struct nodo);

  tmp->dato = dato;

  tmp->sgt = NULL;
  return tmp;
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

void insertarFinal (TpLista &ls) {
  int dato;
  TpLista nodo;

  if (ls == NULL) {
    dato = generarNumero(0, 500);
    nodo = crearNodo(ls, dato);
    ls = nodo;
    return;
  }

  do {
    dato = generarNumero(-500, 500);
  } while (dato > sumaPromedio(ls) / contarLista(ls));

  nodo = crearNodo(ls, dato);

  TpLista tmp = nodo;
  TpLista track = ls;

  while (track->sgt != NULL) {
    track = track->sgt;
  }

  track->sgt = tmp;
}

void insertarImpar (TpLista &ls) {
  TpLista track = ls, ant = NULL, tmp;
  int dato;
  do {
    dato = generarNumero(0, 500);
  } while (dato % 2 == 0);

  tmp = crearNodo(ls, dato);
  int position = contarLista(ls) / 2 + 1;
  for (int i = 0; i < position - 1; i++) {
    ant = track;
    track = track->sgt;
  }

  tmp->sgt = ant->sgt;
  ant->sgt = tmp;
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

int buscarMenor (TpLista ls) {
  if (ls == NULL) {
    return 0;
  }
  int i = 1;
  int indexMenor;
  int menor = ls->dato;
  TpLista tmp = ls;
  while (tmp != NULL) {
    if (menor > tmp->dato) {
      indexMenor = i;
      menor = tmp->dato;
    }
    i++;
    tmp = tmp->sgt;
  }
  cout << "El menor elemento es: " << menor << " || posicion: " << indexMenor << endl;
  return menor;
}

void eliminarDato (TpLista &ls, int menor) {
  if (ls == NULL) {
    cout << "Lista vacia. (Nada para eliminar)" << endl;
    return;
  }

  if (ls->sgt == NULL) {
    ls = NULL;
    return;
  }

  TpLista toDelete = ls, ant = NULL;
  while (toDelete->dato != menor) {
    ant = toDelete;
    toDelete = toDelete->sgt;
  }

  ant->sgt = toDelete->sgt;
  delete toDelete;
}

void menu (TpLista &ls) {
  int opcion, position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Insertar nodo en la Lista Simple.\n2. Insertar impar en el medio.\n3. Mostrar menor valor.\n4. Mostrar Lista Simple\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        insertarFinal(ls);
        mostrarListaSimple(ls);
        break;
      case 2:
        insertarImpar(ls);
        mostrarListaSimple(ls);
        break;
      case 3:
        eliminarDato(ls, buscarMenor(ls));
        mostrarListaSimple(ls);
        break;
      case 4:
        mostrarListaSimple(ls);
        break;
    }
  } while (opcion >= 1 && opcion <= 4);
}

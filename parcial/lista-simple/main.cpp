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
void insertarInicio(TpLista &);
void insertarFinal(TpLista &);
void insertarPosicion(TpLista &, int);
int contarLista(TpLista);
void eliminarInicio(TpLista &);
void eliminarFinal(TpLista &);
void eliminarPosicion(TpLista &, int);
void mostrarListaSimple(TpLista);
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

bool buscarID (int id, TpLista ls) {  
  while (ls != NULL) {
    if (ls->id == id) return true; 
    ls = ls->sgt;
  }
  return false;
}

TpLista crearNodo(TpLista ls) {
  TpLista tmp = new (struct nodo);

  int id, dato;
  do {
    id = generarNumero(100, 300);
  } while (buscarID(id, ls));
  dato = generarNumero(300, 400);
  tmp->dato = dato;
  tmp->id = id;

  tmp->sgt = NULL;
  return tmp;
}

void insertarInicio (TpLista &ls) {
  TpLista tmp = crearNodo(ls);

  tmp->sgt = ls;
  ls = tmp;
}

void insertarFinal (TpLista &ls) {
  TpLista tmp = crearNodo(ls);
  TpLista track = ls;

  while (track->sgt != NULL) {
    track = track->sgt;
  }

  track->sgt = tmp;
}

void insertarPosicion (TpLista &ls, int position) {
  TpLista tmp = crearNodo(ls);
  TpLista track = ls, ant = NULL;

  if (position > contarLista(ls)) return;

  for (int i = 0; i < position - 1; i++) {
    ant = track;
    track = track->sgt;
  }

  tmp->sgt = ant->sgt;
  ant->sgt = tmp;
}

int contarLista (TpLista ls) {
  int cant = 0;

  while (ls != NULL) {
    cant++;
    ls = ls->sgt;
  }

  return cant;
}

void eliminarInicio (TpLista &ls) {
  TpLista tmp = ls;
  ls = ls->sgt;
  delete tmp;
}

void eliminarFinal (TpLista &ls) {
  TpLista track = ls, ant;

  while (track->sgt != NULL) {
    ant = track;
    track = track->sgt;
  }

  ant->sgt = NULL;
  delete track;
}

void eliminarPosicion (TpLista &ls, int position) {
  TpLista track = ls, ant;

  if (position > contarLista(ls)) return;

  for (int i = 0; i < position - 1; i++) {
    ant = track;
    track = track->sgt;
  }

  ant->sgt = track->sgt;
  delete track;
}

void mostrarListaSimple (TpLista ls) {
  int i = 1;
  if (ls == NULL) {
    cout << "Lista Simplemente Enlazada vacía." << endl;
    return;
  }
  while (ls != NULL) {
    cout << i << ") id: "<< ls->id << " || dato: " << ls->dato << endl;
    i++;
    ls = ls->sgt;
  }
}

void menu (TpLista &ls) {
  int opcion, position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Agregar nodo al inicio.\n2. Mostrar Lista Simple.\n3. Insertar nodo al final.\n4. Insertar posición.\n5. Eliminar Inicio.\n6. Eliminar Final.\n7. Eliminar posición.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        insertarInicio(ls);
        mostrarListaSimple(ls);
        break;
      case 2:
        mostrarListaSimple(ls);
        cout << "Tamaño de la lista: " << contarLista(ls) << endl;
        break;
      case 3:
        insertarFinal(ls);
        mostrarListaSimple(ls);
        break;
      case 4:
        cout << "Ingresar posición: " << endl;
        cin >> position;
        insertarPosicion(ls, position);
        mostrarListaSimple(ls);
        break;
      case 5:
        eliminarInicio(ls);
        mostrarListaSimple(ls);
        break;
      case 6:
        eliminarFinal(ls);
        mostrarListaSimple(ls);
        break;
      case 7:
        cout << "Ingresar posición: " << endl;
        cin >> position;
        eliminarPosicion(ls, position);
        mostrarListaSimple(ls);
        break;
    }
  } while (opcion >= 1 && opcion <= 7);
}

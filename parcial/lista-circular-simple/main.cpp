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
void eliminarInicio(TpLista &);
void eliminarFinal(TpLista &);
void eliminarPosicion(TpLista &, int);
void mostrarCircularSimple (TpLista);
int contarListaCircularSimple (TpLista);
void menu(TpLista &);

int main () {
  srand(time(NULL));

  TpLista listaCircularSimple = NULL;

  menu(listaCircularSimple);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}

bool buscarID (int id, TpLista lcs) {
  if (lcs == NULL) {
    return false;
  }
  TpLista tmp = lcs;  
  do {
    if (tmp->id == id) return true; 
    tmp = tmp->sgt;
  } while (tmp->sgt != lcs);
  return false;
}

TpLista crearNodo(TpLista lcs) {
  TpLista tmp = new (struct nodo);

  int id, dato;
  do {
    id = generarNumero(100, 300);
  } while (buscarID(id, lcs));
  dato = generarNumero(300, 400);
  tmp->dato = dato;
  tmp->id = id;

  tmp->sgt = NULL;
  return tmp;
}

void insertarInicio (TpLista &lcs) {
  TpLista newNodo = crearNodo(lcs);

  if (lcs == NULL) {
    lcs = newNodo;
    lcs->sgt = lcs;
    return;
  }

  TpLista last = lcs;
  while (last->sgt != lcs) {
    last = last->sgt;
  }

  last->sgt = newNodo;
  newNodo->sgt = lcs;
  lcs = newNodo;
}

void insertarFinal (TpLista &lcs) {
  TpLista newNodo = crearNodo(lcs);

  if (lcs == NULL) {
    lcs = newNodo;
    lcs->sgt = lcs;
    return;
  }

  TpLista last = lcs;
  while (last->sgt != lcs) {
    last = last->sgt;
  }

  last->sgt = newNodo;
  newNodo->sgt = lcs;
}

void insertarPosicion(TpLista &lcs, int position) {
  if (position >= contarListaCircularSimple(lcs)) return;

  TpLista newNodo = crearNodo(lcs);
  TpLista track = lcs, ant;
  for (int i = 1; i < position; i++) {
    ant = track;
    track = track->sgt;
  }

  newNodo->sgt = track;
  ant->sgt = newNodo;
}

void eliminarInicio (TpLista &lcs) {
  TpLista toDelete = NULL;
  if (lcs == NULL) {
    cout << "Lista Circular Simple vacia. (Nada para eliminar)" << endl;
    return;
  }

  if (lcs->sgt == lcs) {
    toDelete = lcs;
    lcs = NULL;
    delete toDelete;
    return;
  }

  toDelete = lcs;
  TpLista last = lcs;
  while (last->sgt != lcs) {
    last = last->sgt;
  }

  last->sgt = lcs->sgt;
  lcs = lcs->sgt;
  delete toDelete;
}

void eliminarFinal (TpLista &lcs) {
  TpLista toDelete = NULL;
  if (lcs == NULL) {
    cout << "Lista Circular Simple vacia. (Nada para eliminar)" << endl;
    return;
  }

  if (lcs->sgt == lcs) {
    toDelete = lcs;
    lcs = NULL;
    delete toDelete;
    return;
  }

  TpLista last = lcs, ant;
  while (last->sgt != lcs) {
    ant = last;
    last = last->sgt;
  }

  ant->sgt = lcs;
  delete last;
}

void eliminarPosicion (TpLista &lcs, int position) {
  if (position >= contarListaCircularSimple(lcs)) return;

  TpLista toDelete = lcs, ant;
  for (int i = 1; i < position; i++) {
    ant = toDelete;
    toDelete = toDelete->sgt;
  }

  ant->sgt = toDelete->sgt;

  delete toDelete;
}

void mostrarCircularSimple (TpLista lcs) {
  if (lcs == NULL) {
    cout << "Lista Circular Simple vacia. (Nada para mostrar)" << endl;
    return;
  }
  TpLista inicio = lcs;
  int i = 1;
  do {
    cout << i << ") id: " << lcs->id << " || dato: " << lcs->dato << endl;
    lcs = lcs->sgt;
    i++;
  } while (lcs != inicio);
}

int contarListaCircularSimple (TpLista lcs) {
  TpLista inicio = lcs;
  int cant = 0;

  if (lcs == NULL) {
    return 0;
  }

  do {
    lcs = lcs->sgt;
    cant++;
  } while (lcs != inicio);

  return cant;
}

void menu (TpLista &lcs) {
  int opcion;
  int position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Insertar inicio.\n2. Insertar final.\n3. Mostrar Lista Circular Simple.\n4. Insertar posicion.\n5. Eliminar inicio.\n6. Eliminar Final.\n7. Eliminar Posicion.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        insertarInicio(lcs);
        mostrarCircularSimple(lcs);
        break;
      case 2:
        insertarFinal(lcs);
        mostrarCircularSimple(lcs);
        break;
      case 3:
        mostrarCircularSimple(lcs);
        cout << "Cantidad de nodos en la lista circular simple: " << contarListaCircularSimple(lcs) << endl;
        break;
      case 4:
        cout << "Ingresar posicion: " << endl;
        cin >> position;
        insertarPosicion(lcs, position);
        mostrarCircularSimple(lcs);
        break;
      case 5:
        eliminarInicio(lcs);
        mostrarCircularSimple(lcs);
        break;
      case 6:
        eliminarFinal(lcs);
        mostrarCircularSimple(lcs);
        break;
      case 7:
        cout << "Ingresar posicion: " << endl;
        cin >> position;
        eliminarPosicion(lcs, position);
        mostrarCircularSimple(lcs);
        break;
    }
  } while (opcion >= 1 && opcion <= 7);
}

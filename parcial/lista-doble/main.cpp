#include <iostream>
#include <cstdlib>
#include <time.h>

struct nodo {
  int id;
  int dato;
  nodo *sgt;
  nodo *ant;
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
void mostrarListaDoble(TpLista);
void mostrarInverso(TpLista);
void menu(TpLista &);

int main () {
  srand(time(NULL));
  TpLista listaDoble = NULL;

  menu(listaDoble);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}

bool buscarID (int id, TpLista ld) {  
  while (ld != NULL) {
    if (ld->id == id) return true; 
    ld = ld->sgt;
  }
  return false;
}

TpLista crearNodo(TpLista ld) {
  TpLista tmp = new (struct nodo);

  int id, dato;
  do {
    id = generarNumero(100, 300);
  } while (buscarID(id, ld));
  dato = generarNumero(300, 400);
  tmp->dato = dato;
  tmp->id = id;

  tmp->sgt = NULL;
  tmp->ant = NULL;
  return tmp;
}

void insertarInicio (TpLista &ld) {
  TpLista tmp = crearNodo(ld);

  if (ld == NULL) {
    ld = tmp;
    return;
  }

  tmp->sgt = ld;
  tmp->ant = NULL;

  ld->ant = tmp;
  ld = tmp;
}

void insertarFinal (TpLista &ld) {
  TpLista tmp = crearNodo(ld);
  TpLista track = ld;

  while (track->sgt != NULL) {
    track = track->sgt;
  }

  tmp->ant = track;
  track->sgt = tmp;
}

void insertarPosicion (TpLista &ld, int position) {
  TpLista tmp = crearNodo(ld);
  TpLista track = ld, ant = NULL;

  if (position > contarLista(ld)) return;

  for (int i = 0; i < position - 1; i++) {
    ant = track;
    track = track->sgt;
  }

  tmp->sgt = ant->sgt;
  tmp->ant = ant;
  ant->sgt->ant = tmp;
  ant->sgt = tmp;
}

int contarLista(TpLista ld) {
  int cant = 0;

  while (ld != NULL) {
    cant++;
    ld = ld->sgt;
  }

  return cant;
}

void eliminarInicio (TpLista &ld) {
  TpLista tmp = ld;
  if (ld == NULL) {
    cout << "Lista doblemente enlazada vacia." << endl;
    return;
  }
  if (ld->sgt == NULL) {
    ld = NULL;
    delete tmp;
    return;
  }
  ld = ld->sgt;
  ld->ant = NULL;
  delete tmp;
}

void eliminarFinal (TpLista &ld) {
  TpLista track = ld, ant;
  
  while (track->sgt != NULL) {
    ant = track;
    track = track->sgt;
  }
  ant->sgt = NULL;

  delete track;
}

void eliminarPosicion(TpLista &ld, int position) {
  TpLista track = ld, ant;

  if (position > contarLista(ld)) return;

  for (int i = 0; i < position - 1; i++) {
    ant = track;
    track = track->sgt;
  }

  ant->sgt = track->sgt;
  track->sgt->ant = ant;

  delete track;
}

void mostrarListaDoble (TpLista ld) {
  int i = 1;
  if (ld == NULL) {
    cout << "Lista Doblemente Enlazada vacía." << endl;
    return;
  }
  while (ld != NULL) {
    cout << i << ") id: "<< ld->id << " || dato: " << ld->dato << endl;
    i++;
    ld = ld->sgt;
  }
}

void mostrarInverso(TpLista ld) {
  int i = 1;
  while (ld->sgt != NULL) {
    ld = ld->sgt;
  }

  while (ld != NULL) {
    cout << i << ") id: "<< ld->id << " || dato: " << ld->dato << endl;
    ld = ld->ant;
    i++;
  }
}

void menu (TpLista &ld) {
  int opcion, position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Agregar nodo al inicio.\n2. Mostrar Lista Doble.\n3. Insertar nodo al final.\n4. Insertar posición.\n5. Eliminar Inicio.\n6. Eliminar Final.\n7. Eliminar posición.\n8. Mostrar en orden reverso.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        insertarInicio(ld);
        mostrarListaDoble(ld);
        break;
      case 2:
        mostrarListaDoble(ld);
        break;
      case 3:
        insertarFinal(ld);
        mostrarListaDoble(ld);
        break;
      case 4:
        cout << "Ingresar posición: " << endl;
        cin >> position;
        insertarPosicion(ld, position);
        mostrarListaDoble(ld);
        break;
      case 5:
        eliminarInicio(ld);
        mostrarListaDoble(ld);
        break;
      case 6:
        eliminarFinal(ld);
        mostrarListaDoble(ld);
        break;
      case 7:
        cout << "Ingresar posición: " << endl;
        cin >> position;
        eliminarPosicion(ld, position);
        mostrarListaDoble(ld);
        break;
      case 8:
        mostrarInverso(ld);
        break;
    }
  } while (opcion >= 1 && opcion <= 8);
}

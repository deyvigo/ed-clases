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
void encolar(TpLista &);
void desencolar(TpLista &);
void mostrarColaDoble(TpLista);
void recorridoInverso (TpLista);
int contarColaDoble(TpLista);
void menu(TpLista &);

int main () {
  srand(time(NULL));

  TpLista colaDoble = NULL;

  menu(colaDoble);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}

bool buscarID (int id, TpLista cd) {
  while (cd != NULL) {
    if (cd->id == id) return true; 
    cd = cd->sgt;
  }
  return false;
}

TpLista crearNodo(TpLista cd) {
  TpLista tmp = new (struct nodo);

  int id, dato;
  do {
    id = generarNumero(100, 300);
  } while (buscarID(id, cd));
  dato = generarNumero(300, 400);
  tmp->dato = dato;
  tmp->id = id;

  tmp->sgt = NULL;
  tmp->ant = NULL;
  return tmp;
}

void encolar (TpLista &cd) {
  TpLista tmp = crearNodo(cd);
  if (cd == NULL) {
    cd = tmp;
    return;
  }
  TpLista track = cd;
  while (track->sgt != NULL) {
    track = track->sgt;
  }
  track->sgt = tmp;
  tmp->ant = track;
}

void desencolar (TpLista &cd) {
  TpLista tmp = cd;
  if (cd == NULL) {
    cout << "Cola doblemente enlazada vacia." << endl;
    return;
  }

  // Si solo queda uno
  if (cd->sgt == NULL) {
    cd = NULL;
    delete tmp;
    return;
  }

  cd = cd->sgt;
  cd->ant = NULL;

  delete tmp;
}

void mostrarColaDoble (TpLista cd) {
  int i = 1;
  if (cd == NULL) {
    cout << "Cola Doblemente Enlazada vacía." << endl;
    return;
  }
  while (cd != NULL) {
    cout << i << ") id: " << cd->id << " || dato: " << cd->dato << endl;
    i++;
    cd = cd->sgt;
  }
}

void recorridoInverso (TpLista cd) {
  if (cd == NULL) {
    cout << "Cola Doblemente Enlazada vacía." << endl;
    return;
  }
  while (cd->sgt != NULL) {
    cd = cd->sgt;
  }
  int i = 1;
  while (cd != NULL) {
    cout << i << ") id: " << cd->id << " || dato: " << cd->dato << endl;
    cd = cd->ant;
    i++;
  }
}

int contarColaDoble(TpLista cd) {
  int cant = 0;

  while (cd != NULL) {
    cant++;
    cd = cd->sgt;
  }

  return cant;
}

void menu (TpLista &cd) {
  int opcion, position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Encolar.\n2. Desencolar.\n3. Mostar cola doble.\n4. Recorrido inverso.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        encolar(cd);
        mostrarColaDoble(cd);
        break;
      case 2:
        desencolar(cd);
        mostrarColaDoble(cd);
        break;
      case 3:
        mostrarColaDoble(cd);
        cout << "Cantidad de nodos de la Cola Simple: " << contarColaDoble(cd) << endl;
        break;
      case 4:
        recorridoInverso(cd);
        break;
    }
  } while (opcion >= 1 && opcion <= 4);
}

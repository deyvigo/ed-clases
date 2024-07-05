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
void encolar(TpLista &);
void desencolar(TpLista &);
int contarColaSimple(TpLista);
void mostrarColaSimple(TpLista);
void menu(TpLista &);

int main () {
  srand(time(NULL));

  TpLista colaSimple = NULL;

  menu(colaSimple);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}

bool buscarID (int id, TpLista cs) {
  while (cs != NULL) {
    if (cs->id == id) return true; 
    cs = cs->sgt;
  }
  return false;
}

TpLista crearNodo(TpLista cs) {
  TpLista tmp = new (struct nodo);

  int id, dato;
  do {
    id = generarNumero(100, 300);
  } while (buscarID(id, cs));
  dato = generarNumero(300, 400);
  tmp->dato = dato;
  tmp->id = id;

  tmp->sgt = NULL;
  return tmp;
}

void encolar (TpLista &cs) {
  if (contarColaSimple(cs) >= 5) {
    cout << "Cola Simplemente Enlazada llena.\n";
    return;
  }
  TpLista tmp = crearNodo(cs);
  TpLista track = cs;

  if (cs == NULL) {
    cs = tmp;
    return;
  }

  while (track->sgt != NULL) {
    track = track->sgt;
  }

  track->sgt = tmp;
}

void desencolar (TpLista &cs) {
  if (cs == NULL) {
    cout << "Cola Simple vacia." << endl;
    return;
  }
  TpLista tmp = cs;

  cs = cs->sgt;
  
  delete tmp;
}

int contarColaSimple (TpLista cs) {
  int cant = 0;

  while (cs != NULL) {
    cant++;
    cs = cs->sgt;
  }

  return cant;
}

void mostrarColaSimple (TpLista cs) {
  int i = 1;
  if (cs == NULL) {
    cout << "Cola Simplemente Enlazada vacía." << endl;
    return;
  }
  while (cs != NULL) {
    cout << i << ") id: "<< cs->id << " || dato: " << cs->dato << endl;
    i++;
    cs = cs->sgt;
  }
}

void menu (TpLista &cs) {
  int opcion, position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Encolar.\n2. Desencolar.\n3. Mostar cola simple.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        encolar(cs);
        mostrarColaSimple(cs);
        break;
      case 2:
        desencolar(cs);
        mostrarColaSimple(cs);
        break;
      case 3:
        mostrarColaSimple(cs);
        cout << "Cantidad de nodos de la Cola Simple: " << contarColaSimple(cs) << endl;
        break;
    }
  } while (opcion >= 1 && opcion <= 3);
}

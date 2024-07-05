#include <iostream>
#include <cstdlib>
#include <time.h>

struct nodo {
  int id;
  char destino;
  nodo *sgt;
};

using namespace std;
typedef struct nodo *TpLista;

int generarNumero();
char generarDestino(int);
TpLista crearNodo(int, char);
void push(TpLista &, int &);
bool buscar(TpLista, int);
void mostrar(TpLista);
TpLista pop(TpLista &, int &);
void encolarUno (TpLista &, TpLista); 
void encolar(TpLista &, TpLista &, TpLista);
void desencolar (TpLista &);
void menu (TpLista &, TpLista &, TpLista &, int &);

int main () {
  srand(time(NULL));

  TpLista pila = NULL;
  int cantPila = 0;

  TpLista colaNacional = NULL;
  TpLista colaInternacional = NULL;

  menu (pila, colaNacional, colaInternacional, cantPila);
}

int generarNumero () {
  return rand() % 300;
}

char generarDestino (int id) {
  return id % 2 == 0 ? 'N' : 'I';
}

TpLista crearNodo (int id, char destino) {
  TpLista tmp = new (struct nodo);
  tmp->id = id;
  tmp->destino = destino;
  tmp->sgt = NULL;
  return tmp;
}

bool buscar (TpLista p, int dato) {
  while (p != NULL) {
    if (p->id == dato) {
      return true;
    }
    p = p->sgt;
  }
  return false;
}

void push (TpLista &p, int &cant) {
  if (cant <= 7) {
    int id;
    do {
      id = generarNumero();
    } while (buscar(p, id));
    char destino = generarDestino(id);
    TpLista tmp = crearNodo(id, destino);
    tmp->sgt = p;
    p = tmp;
    cant++;
  }
}

void mostrar (TpLista l) {
  int index = 1;
  while (l != NULL) {
    cout << index << ": " << l->id << " || " << l->destino << endl;
    index++;
    l = l->sgt;
  }
}

TpLista pop(TpLista &p, int &cant) {
  if (p == NULL) {
    return NULL;
  }
  TpLista tmp = p;
  p = tmp->sgt;
  tmp->sgt = NULL;
  cant--;
  return tmp;
}

void encolarUno (TpLista &cola, TpLista nodo) {
  if (cola == NULL) {
    cola = nodo;
    return;
  }
  TpLista tmp = cola;
  while (tmp->sgt != NULL) {
    tmp = tmp->sgt;
  }
  tmp->sgt = nodo;
}

void encolar (TpLista &colaN, TpLista &colaI, TpLista nodo) {
  if (nodo == NULL) {
    return;
  }
  if (nodo->destino == 'N') {
    encolarUno(colaN, nodo);
  } else {
    encolarUno(colaI, nodo);
  }
}

void desencolar (TpLista &l) {
  if (l == NULL) {
    return;
  }
  l = l->sgt;
}

void menu (TpLista &pila, TpLista &cNac, TpLista &cInter, int &cant) {
  int opcion = 0;
  TpLista tmp = NULL;
  char cola;
  do {
    cout << "1. Recibir sobres.\n2. Distribuir sobres.\n3. Enviar Sobre\n";
    cin >> opcion;
    switch (opcion) {
      case 1:
        push(pila, cant);
        cout << "\nPila:\n";
        cout << "-----------------------------------\n";
        mostrar(pila);
        cout << "-----------------------------------\n";
        break;
      case 2:
        tmp = pop(pila, cant);
        encolar(cNac, cInter, tmp);
        cout << "\nCola Nacional:\n";
        cout << "-----------------------------------\n";
        mostrar(cNac);
        cout << "\nCola Internacional:\n";
        cout << "-----------------------------------\n";
        mostrar(cInter);
        cout << "-----------------------------------\n";
        break;
      case 3:
        cout << "Elige la cola nacional o internacional: (N o I)\n";
        cin >> cola;
        switch (cola) {
          case 'N':
          case 'n':
            desencolar(cNac);
            cout << "Cola Nacional:\n";
            cout << "-----------------------------------\n";
            mostrar(cNac);
            cout << "-----------------------------------\n";
            break;
          case 'I':
          case 'i':
            desencolar(cInter);
            cout << "Cola Internacional:\n";
            cout << "-----------------------------------\n";
            mostrar(cInter);
            cout << "-----------------------------------\n";
            break;
        }
        break;
    }
  } while (opcion == 1 || opcion == 2 || opcion == 3);
}
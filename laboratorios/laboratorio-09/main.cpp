#include <iostream>
#include <cstdlib>
#include <time.h>

struct nodo {
  int dato;
  nodo *izq;
  nodo *der;
};

using namespace std;
typedef struct nodo *TpLista;

struct nodoP {
  TpLista node;
  nodoP *sgt;
};

typedef struct nodoP *NodoPila;

int generarNumero (int, int);
TpLista crearHoja ();
void agregarNodo (TpLista &);
void inOrdenIterativo (TpLista, NodoPila &);
void inOrdenRecursivo (TpLista);
void preOrdenRecursivo (TpLista);
void postOrdenRecursivo (TpLista);
void push (NodoPila &, TpLista);
TpLista pop (NodoPila &);
void menu (TpLista &, NodoPila &);

int main () {
  srand(time(NULL));

  NodoPila pila = NULL;

  TpLista arbolBB = NULL;

  menu(arbolBB, pila);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}

TpLista crearHoja () {
  TpLista tmp = new (struct nodo);
  tmp->dato = generarNumero(100, 400);
  tmp->der = NULL;
  tmp->izq = NULL;

  return tmp;
}

void agregarNodo (TpLista &root) {
  TpLista newNodo = crearHoja();
  int nivel = 1;
  cout << "Se agregará el elemento: " << newNodo->dato << endl;
  if (root == NULL) {
    root = newNodo;
    cout << "* Agregado en el nivel: " << nivel << endl;
    return;
  }

  TpLista track = root;
  while (true) {
    if (nivel >= 3) {
      cout << "Solo se agregarán hasta el nivel 3." << endl;
      return;
    }
    if (track->dato == newNodo->dato) {
      cout << "El elemento ya existe en el arbol binario de busqueda." << endl;
      return;
    }
    
    if (track->dato >= newNodo->dato) {
      nivel++;
      if (track->izq == NULL) {
        track->izq = newNodo;
        cout << "* Agregado en el nivel: " << nivel << endl;
        break;
      }
      track = track->izq;
    } else {
      nivel++;
      if (track->der == NULL) {
        track->der = newNodo;
        cout << "* Agregado en el nivel: " << nivel << endl;
        break;
      }
      track = track->der;
    }
  }
}

// izq, root, der
void inOrdenIterativo (TpLista root, NodoPila &pila) {
  TpLista actual = root;
  while (actual != NULL || pila != NULL) {
    while (actual != NULL) {
      push(pila, actual);
      actual = actual->izq;
    }
    actual = pop(pila);
    cout << actual->dato << " || ";
    actual = actual->der;
  }
}

void inOrdenRecursivo (TpLista root) {
  if (root == NULL) {
    return;
  }
  inOrdenRecursivo(root->izq);
  cout << root->dato << " || ";
  inOrdenRecursivo(root->der); 
}

void preOrdenRecursivo (TpLista root) {
  if (root == NULL) {
    return;
  }
  cout << root->dato << " || ";
  preOrdenRecursivo(root->izq);
  preOrdenRecursivo(root->der);
}

void postOrdenRecursivo (TpLista root) {
  if (root == NULL) {
    return;
  }
  postOrdenRecursivo(root->izq);
  postOrdenRecursivo(root->der);
  cout << root->dato << " || ";
}

void push (NodoPila &p, TpLista a) {
  NodoPila newNodoPila = new (struct nodoP);
  newNodoPila->node = a;
  newNodoPila->sgt = NULL;
  if (p == NULL) {
    p = newNodoPila;
    return;
  }
  newNodoPila->sgt = p;
  p = newNodoPila;
}

TpLista pop (NodoPila &p) {
  if (p == NULL) {
    return NULL;
  }
  TpLista toReturn = p->node;
  p = p->sgt;
  return toReturn;
}

void menu (TpLista &root, NodoPila &pila) {
  int opcion;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Insertar Elemento.\n2. Mostrar Postorden (izq, der, root).\n3. Mostrar Preorden (root, izq, der).\n4. Mostrar Inorden (izq, root, der).\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        agregarNodo(root);
        cout << "Recorrido inOrden Iterativo (izq, root, der): " << endl;
        inOrdenIterativo(root, pila);
        cout << endl;
        break;
      case 2:
        cout << "Recorrido postOrden Recursivo: " << endl;
        postOrdenRecursivo(root);
        cout << endl;
        break;
      case 3:
        cout << "Recorrido preOrden Recursivo: " << endl;
        preOrdenRecursivo(root);
        cout << endl;
        break;
      case 4:
        cout << "Recorrido inOrden Recursivo: " << endl;
        inOrdenRecursivo(root);
        cout << endl;
        break;
    }
  } while (opcion >= 1 && opcion <= 4);
}

#include <iostream>
#include <cstdlib>
#include <time.h>

struct nodo {
  int peso;
  int id;
  struct nodo *sgt;
  struct nodo *ant;
};

using namespace std;
typedef struct nodo *TpLista;

int generarNumero(int, int);
TpLista crearNodo();
bool buscar(int, TpLista);
int generarId(TpLista);
void insertarNodoListaDoble(TpLista &);
void mostrarListaDoble(TpLista);
TpLista eliminarNodoListaDoble(TpLista &, int);
void recorrerAntihorario(TpLista &, TpLista &);
int contarListaDoble(TpLista);
void mostrarAntihorario(TpLista);
void insertarListaEnlazadaSimple(TpLista &, TpLista);
void mostrarListaEnlazadaSimple (TpLista);
void menu(TpLista &, TpLista &);

int main () {
  srand(time(NULL));
  TpLista listaCircularDoble = NULL;
  TpLista listaSimple = NULL;

  menu(listaCircularDoble, listaSimple);

  return 0;
}

int generarNumero (int menor, int mayor) {
  int random;
  random = menor + rand()%(mayor - menor + 1);
  return random;
}

TpLista crearNodo () {
  TpLista tmp = new (struct nodo);
  tmp->ant = NULL;
  tmp->sgt = NULL;
  return tmp;
}

bool buscar (int id, TpLista l) {
  if (l == NULL) {
    return false;
  }
  TpLista t = l;
  do {
    if (t->id == id) {
      return true;
    }
    t = t->sgt;
  } while (t->sgt != l);
  return false;
}

int generarId (TpLista l) {
  int random;
  if (l == NULL) {
    return generarNumero(100, 900);
  }
  do {
    random = generarNumero(100, 900);
  } while (buscar(random, l));
  return random;
}

// Inserta atras de lista
void insertarNodoListaDoble (TpLista &lista) {
  TpLista tmp = crearNodo();
  tmp->id = generarId(lista);
  tmp->peso = generarNumero(100, 300);

  if (lista == NULL) {
    // Inicializar los punteros de tmp con tmp porque lista es NULL
    tmp->ant = tmp;
    tmp->sgt = tmp;
    lista = tmp;
    return;
  }
  tmp->ant = lista->ant;
  tmp->sgt = lista;
  lista->ant->sgt = tmp;
  lista->ant = tmp;
}

void mostrarListaDoble (TpLista lista) {
  if (lista == NULL) {
    cout << "\nLista vacia\n\n";
    return;
  }
  TpLista t = lista;
  int i = 0;
  cout << "----------- LISTA CIRCULAR DOBLE -----------\n\n";
  cout << "IDA\n";
  do {
    cout << i + 1 << ") id: " << t->id << " || peso: " << t->peso << endl;
    t = t->sgt;
    i++;
  } while (t != lista);

  cout << "*********************************************\n";
  t = lista->ant;
  cout << "VUELTA\n";
  do {
    cout << i << ") id: " << t->id << " || peso: " << t->peso << endl;
    t = t->ant;
    i--;
  } while (t != lista->ant);
  cout << "\n----------- LISTA CIRCULAR DOBLE -----------\n\n";
}

TpLista eliminarNodoListaDoble (TpLista &lista, int id) {
  TpLista remove = NULL;
  TpLista current = lista;

  if (lista == NULL) {
    cout << "\nLa lista está vacia\n";
    return NULL;
  }

  // buscar el elemento a eliminar
  while (current->id != id) {
    current = current->sgt;
  }
  remove = current;
 
  // si solo hay un nodo en la lista
  if (lista == lista->sgt) {
    lista->ant = NULL;
    lista->sgt = NULL;
    lista = NULL;
  } else {
    remove->ant->sgt = remove->sgt;
    remove->sgt->ant = remove->ant;
    // si se borra el "primer" elemento de la lista
    if (remove == lista) {
      lista = remove->sgt;
    }
  }
  return remove;
}

void recorrerAntihorario (TpLista &lista, TpLista &listaSimple) {
  if (lista == NULL) {
    cout << "\nLista circular doble vacia\n";
    return;
  }
  TpLista t = lista->ant, remove = NULL;
  do {
    t->peso -= 50;
    // cout << "id: " << t->id << " || peso: " << t->peso;
    if (t->peso <= 0) {
      // cout << " <- Eliminar " << " ||  ";
      remove = eliminarNodoListaDoble(lista, t->id);
      cout << endl;
      cout << "Borrado -> id: " << remove->id << " || peso: " << remove->peso << endl;
      cout << endl;
      insertarListaEnlazadaSimple(listaSimple, remove);
      mostrarListaEnlazadaSimple(listaSimple);
    }
    if (lista != NULL) {
      t = t->ant;
    } else {
      break;
    }
  } while (t != lista->ant);
}

void mostrarAntihorario (TpLista lista) {
  if (lista == NULL) {
    cout << "\nLista vacia\n";
  } else {
    TpLista t = lista->ant;
    cout << endl;
    cout << "ANTIHORARIO\n";
    do {
      cout << "id: " << t->id << " || peso: " << t->peso << endl;
      t = t->ant;
    } while (t != lista->ant);
    cout << "ANTIHORARIO\n";
    cout << endl;
  }
}

void insertarListaEnlazadaSimple (TpLista &lista, TpLista nodo) {
  nodo->sgt = NULL;
  if (lista == NULL) {
    lista = nodo;
  } else {
    TpLista last = lista;
    while (last->sgt != NULL) {
      last = last->sgt;
    }
    last->sgt = nodo;
  }
}

void mostrarListaEnlazadaSimple (TpLista l) {
  if (l == NULL) {
    cout << "\nLista enlazada simple vacia\n";
    return;
  }
  int i = 0;
  cout << "\n---------- LISTA ENLAZADA SIMPLE ----------\n\n";
  while (l != NULL) {
    cout << i + 1 << ") id: " << l->id << " || peso: " << l->peso << endl;
    l = l->sgt;
    i++;
  }
  cout << "\n---------- LISTA ENLAZADA SIMPLE ----------\n\n";
}

void menu (TpLista &listaCircularDoble, TpLista &listaSimple) {
  int opcion;
  do {
    cout << "1. Agregar nodo.\n2. Recorrer antihorario y disminuir pesos en 50.\n3. Mostrar.\n";
    cin >> opcion;
    switch (opcion) {
    case 1:
      insertarNodoListaDoble(listaCircularDoble);
      mostrarListaDoble(listaCircularDoble);
      break;
    case 2:
      recorrerAntihorario(listaCircularDoble, listaSimple);
      mostrarAntihorario(listaCircularDoble);
      break;
    case 3:
      mostrarListaDoble(listaCircularDoble);
      break;
    }
  } while (opcion == 1 || opcion == 2 || opcion == 3);
}

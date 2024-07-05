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
void insertarFinal(TpLista &);
void mostrarCircularDoble (TpLista);
void mostrarCircularDobleInverso(TpLista);
void recorrerInverso(TpLista &, TpLista &);
TpLista eliminar(TpLista &, int);
void insertarListaSimple (TpLista &, TpLista);
void mostrarListaSimple (TpLista);
void menu(TpLista &, TpLista &);

int main () {
  srand(time(NULL));

  TpLista listaCircularDoble = NULL;
  TpLista listaSimple = NULL;

  menu(listaCircularDoble, listaSimple);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}

bool buscarID (int id, TpLista lcd) {
  if (lcd == NULL) {
    return false;
  }
  TpLista tmp = lcd;  
  do {
    if (tmp->id == id) return true; 
    tmp = tmp->sgt;
  } while (tmp->sgt != lcd);
  return false;
}

TpLista crearNodo(TpLista lcd) {
  TpLista tmp = new (struct nodo);

  int id, dato;
  do {
    id = generarNumero(500, 900);
  } while (buscarID(id, lcd));
  dato = generarNumero(100, 300);
  tmp->dato = dato;
  tmp->id = id;

  tmp->sgt = NULL;
  tmp->ant = NULL;
  return tmp;
}

void insertarFinal (TpLista &lcd) {
  TpLista newNodo = crearNodo(lcd);

  if (lcd == NULL) {
    lcd = newNodo;
    lcd->sgt = lcd;
    lcd->ant = lcd;
    return;
  }

  TpLista last = lcd;
  while (last->sgt != lcd) {
    last = last->sgt;
  }

  newNodo->sgt = lcd;
  newNodo->ant = last;
  last->sgt = newNodo;
  lcd->ant = newNodo;
}

void mostrarCircularDoble (TpLista lcd) {
  if (lcd == NULL) {
    cout << "Lista Circular Doble vacia. (Nada para mostrar)" << endl;
    return;
  }
  TpLista inicio = lcd;
  int i = 1;
  cout << "+++++ IDA +++++" << endl;
  do {
    cout << i << ") id: " << lcd->id << " || dato: " << lcd->dato << endl;
    lcd = lcd->sgt;
    i++;
  } while (lcd != inicio);

  cout << endl << "++++ VUELTA +++++" << endl;
  lcd = inicio->ant;
  inicio = inicio->ant;
  i--;
  do {
    cout << i << ") id: " << lcd->id << " || dato: " << lcd->dato << endl;
    lcd = lcd->ant;
    i--;
  } while (lcd != inicio);
}

void mostrarCircularDobleInverso (TpLista lcd) {
  if (lcd == NULL) {
    cout << "No hay elementos para recorrer. (Lista Circular Doble vacía.)" << endl;
    return;
  }
  TpLista last = lcd->ant, track = lcd->ant;
  do {
    cout << "* id: " << track->id << " || dato: " << track->dato << endl;
    track = track->ant;
  } while (track != last);
}

void recorrerInverso (TpLista &lcd, TpLista &ls) {
  if (lcd == NULL) {
    cout << "No hay elementos para recorrer. (Lista Circular Doble vacía.)" << endl;
    return;
  }
  TpLista last = lcd->ant, track = lcd->ant, tmp, deleted;
  do {
    track->dato -= 50;
    tmp = track;
    if (track->dato <= 0) {
      deleted = eliminar(lcd, track->id);
      insertarListaSimple(ls, deleted);
    }
    if (deleted == last) {
      track = track->sgt;
    }
    track = track->ant;
    if (lcd != NULL) last = lcd->ant;
  } while (track != last);
}

TpLista eliminar (TpLista &lcd, int id) {
  TpLista ant, sgt, track = lcd;
  if (lcd == NULL) {
    cout << "Nada para eliminar. (Lista Circular Doble vacía)." << endl;
    return NULL;
  }

  if (lcd->sgt == lcd) {
    cout << "- id: " << track->id << " || dato: " << track->dato << " <-- se eliminó" << endl; 
    track = lcd;
    lcd = NULL;
    return track;
  }

  do {
    track = track->sgt;
  } while (track->id != id);

  cout << "- id: " << track->id << " || dato: " << track->dato << " <-- se eliminó" << endl; 

  ant = track->ant;
  sgt = track->sgt;
  ant->sgt = sgt;
  sgt->ant = ant;
  
  if (track == lcd) {
    lcd = track->ant->sgt; // Para mantener el elemento "final"
  }

  return track;
}

void insertarListaSimple (TpLista &ls, TpLista tmp) {
  if (tmp == NULL) {
    return;
  }

  // Crear un nuevo nodo para evitar errores con los punteros a lcd
  TpLista node = new (struct nodo);
  node->dato = tmp->dato;
  node->id = tmp->id;
  node->sgt = NULL;
  node->ant = NULL;

  if (ls == NULL) {
    ls = node;
    return;
  }

  TpLista track = ls;
  while (track->sgt != NULL) {
    track = track->sgt;
  }

  track->sgt = node;
}

void mostrarListaSimple (TpLista ls) {
  if (ls == NULL) {
    cout << "Lista Simple vacía." << endl;
    return;
  }

  int i = 1;
  while (ls != NULL) {
    cout << i << ") id: " << ls->id << " || dato: " << ls->dato << endl;
    ls = ls->sgt;
    i++;
  }
}

void menu (TpLista &lcd, TpLista &ls) {
  int opcion;
  int position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Insertar nodo.\n2. Recorrer inverso.\n3. Mostrar.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        insertarFinal(lcd);
        mostrarCircularDoble(lcd);
        break;
      case 2:
        recorrerInverso(lcd, ls);
        cout << endl << "Lista Circular Doble: " << endl;
        mostrarCircularDobleInverso(lcd);
        cout << endl << "Lista Simple: " << endl;
        mostrarListaSimple(ls);
        break;
      case 3:
        mostrarCircularDoble(lcd);
        break;
    }
  } while (opcion >= 1 && opcion <= 3);
}

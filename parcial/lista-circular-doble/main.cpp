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
void eliminarInicio(TpLista &);
void eliminarFinal(TpLista &);
void eliminarPosicion(TpLista &, int);
void mostrarCircularDoble (TpLista);
int contarListaCircularDoble (TpLista);
void menu(TpLista &);

int main () {
  srand(time(NULL));

  TpLista listaCircularDoble = NULL;

  menu(listaCircularDoble);

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
    id = generarNumero(100, 300);
  } while (buscarID(id, lcd));
  dato = generarNumero(300, 400);
  tmp->dato = dato;
  tmp->id = id;

  tmp->sgt = NULL;
  tmp->ant = NULL;
  return tmp;
}

void insertarInicio (TpLista &lcd) {
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
  
  lcd = newNodo;
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

void insertarPosicion (TpLista &lcd, int position) {
  if (position >= contarListaCircularDoble(lcd)) return;

  TpLista newNodo = crearNodo(lcd);
  TpLista track = lcd, ant;
  for (int i = 1; i < position; i++) {
    ant = track;
    track = track->sgt;
  }

  newNodo->sgt = track;
  newNodo->ant = ant;
  ant->sgt = newNodo;
  track->ant = newNodo;
}

void eliminarInicio (TpLista &lcd) {
  TpLista toDelete = NULL;
  if (lcd == NULL) {
    cout << "Lista Circular Doble vacia. (Nada para eliminar)" << endl;
    return;
  }

  if (lcd->sgt == lcd) {
    toDelete = lcd;
    lcd = NULL;
    delete toDelete;
    return;
  }

  toDelete = lcd;
  TpLista last = lcd->ant;

  last->sgt = lcd->sgt;
  lcd = lcd->sgt;
  lcd->ant = last;
  delete toDelete;
}
void eliminarFinal (TpLista &lcd) {
  TpLista toDelete = NULL;
  if (lcd == NULL) {
    cout << "Lista Circular Simple vacia. (Nada para eliminar)" << endl;
    return;
  }

  if (lcd->sgt == lcd) {
    toDelete = lcd;
    lcd = NULL;
    delete toDelete;
    return;
  }

  TpLista ant;
  toDelete = lcd->ant;
  ant = toDelete->ant;

  ant->sgt = lcd;
  lcd->ant = ant;

  delete toDelete;
}

void eliminarPosicion (TpLista &lcd, int position) {
  if (position >= contarListaCircularDoble(lcd)) return;

  TpLista toDelete = lcd, ant;
  for (int i = 1; i < position; i++) {
    ant = toDelete;
    toDelete = toDelete->sgt;
  }

  ant->sgt = toDelete->sgt;
  toDelete->sgt->ant = ant;

  delete toDelete;
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

  cout << "++++ VUELTA +++++" << endl;
  lcd = inicio->ant;
  inicio = inicio->ant;
  i--;
  do {
    cout << i << ") id: " << lcd->id << " || dato: " << lcd->dato << endl;
    lcd = lcd->ant;
    i--;
  } while (lcd != inicio);
}

int contarListaCircularDoble (TpLista lcd) {
  TpLista inicio = lcd;
  int cant = 0;

  if (lcd == NULL) {
    return 0;
  }

  do {
    lcd = lcd->sgt;
    cant++;
  } while (lcd != inicio);

  return cant;
}

void menu (TpLista &lcd) {
  int opcion;
  int position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Insertar inicio.\n2. Insertar final.\n3. Mostrar Lista Circular Doble.\n4. Insertar posicion.\n5. Eliminar inicio.\n6. Eliminar Final.\n7. Eliminar Posicion.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        insertarInicio(lcd);
        mostrarCircularDoble(lcd);
        break;
      case 2:
        insertarFinal(lcd);
        mostrarCircularDoble(lcd);
        break;
      case 3:
        mostrarCircularDoble(lcd);
        cout << "Cantidad de nodos en la Lista Circular Doble: " << contarListaCircularDoble(lcd) << endl;
        break;
      case 4:
        cout << "Ingresar posicion: " << endl;
        cin >> position;
        insertarPosicion(lcd, position);
        mostrarCircularDoble(lcd);
        break;
      case 5:
        eliminarInicio(lcd);
        mostrarCircularDoble(lcd);
        break;
      case 6:
        eliminarFinal(lcd);
        mostrarCircularDoble(lcd);
        break;
      case 7:
        cout << "Ingresar posicion: " << endl;
        cin >> position;
        eliminarPosicion(lcd, position);
        mostrarCircularDoble(lcd);
        break;
    }
  } while (opcion >= 1 && opcion <= 7);
}

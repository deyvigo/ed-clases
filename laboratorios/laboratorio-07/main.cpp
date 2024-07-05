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
void insertarFinal(TpLista &);
void mostrarCircularSimple (TpLista);
int contarListaCircularSimple (TpLista);
void stats (TpLista);
void metodoBurbuja(TpLista &);
void menu(TpLista &);

int main () {
  srand(time(NULL));

  TpLista paquetes = NULL;

  menu(paquetes);

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

void stats (TpLista lcs) {
  TpLista inicio = lcs;
  float sum = 0;

  if (lcs == NULL) {
    return;
  }

  do {
    sum += lcs->dato;
    lcs = lcs->sgt;
  } while (lcs != inicio);

  cout << "El peso total es: " << sum << endl;
  cout << "El promedio de pesos es: " << sum / contarListaCircularSimple(lcs) << endl;
}

void metodoBurbuja (TpLista &lcs) {
  int size = contarListaCircularSimple(lcs), steps = 0;
  TpLista tmp2 = NULL;
  TpLista tmp3 = NULL, aux = new (struct nodo);
  if (lcs == NULL || lcs->sgt == lcs) {
    cout << "\nNada que ordenar." << endl;
    return;
  }

  for (int i = 0; i < size - 1; i++) {
    tmp2 = lcs;
    for (int j = 0; j < size - 1 - steps; j++) {
      tmp3 = tmp2->sgt;
      if (tmp2->dato > tmp3->dato) {
        aux->dato = tmp2->dato;
        aux->id = tmp2->id;
        tmp2->id = tmp3->id;
        tmp2->dato = tmp3->dato;
        tmp3->dato = aux->dato;
        tmp3->id = aux->id;
      }
      tmp2 = tmp2->sgt;
    };
    steps++;
  };
}

void menu (TpLista &lcs) {
  int opcion;
  int position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Agregar paquete.\n2. Cantidad de paquetes.\n3. Peso total y peso promedio.\n4. Ordenar.\n5. Mostrar.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        insertarFinal(lcs);
        mostrarCircularSimple(lcs);
        break;
      case 2:
        cout << "Cantidad de paquetes: " << contarListaCircularSimple(lcs) << endl;
        break;
      case 3:
        stats(lcs);
        break;
      case 4:
        metodoBurbuja(lcs);
        mostrarCircularSimple(lcs);
        break;
      case 5:
        mostrarCircularSimple(lcs);
        break;
    }
  } while (opcion >= 1 && opcion <= 7);
}

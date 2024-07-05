#include <iostream>
#include <cstdlib>
#include <time.h>

struct nodo {
  int pesoUno;
  int pesoDos;
  int pesoTres;
  nodo *sgt;
  nodo *ant;
};

using namespace std;
typedef struct nodo *TpLista;

int generarNumero(int, int);
TpLista crearNodo(TpLista);
void push(TpLista &);
TpLista pop (TpLista &);
int contarPila(TpLista);
void mostrarPila (TpLista);
void insertarFinal (TpLista &, TpLista);
void mostrarListaDoble (TpLista);
void mostrarListaDobleCompleta (TpLista);
void asignarPesos (TpLista &);
void filtrar(TpLista &);
void eliminarDato(TpLista &, int, int, int);
void menu (TpLista &ls, TpLista &p);

int main () {
  srand(time(NULL));

  TpLista pila = NULL;
  TpLista listaDoble = NULL;
  
  menu(listaDoble, pila);

  return 0;
}

int generarNumero (int menor, int mayor) {
  return menor + rand() % (mayor - menor + 1);
}

TpLista crearNodo(TpLista ls) {
  TpLista tmp = new (struct nodo);

  tmp->pesoDos = 0;
  tmp->pesoUno = 0;
  tmp->pesoTres = 0;
  tmp->sgt = NULL;
  tmp->ant = NULL;
  return tmp;
}

void push (TpLista &p) {
  if (contarPila(p) >=5) {
    cout << "Pila llena." << endl;
    return;
  }
  TpLista tmp = crearNodo(p);
  tmp->pesoDos = generarNumero(10, 50);

  tmp->sgt = p;
  p = tmp;
}

int contarPila (TpLista p) {
  int cant = 0;

  while (p != NULL) {
    cant++;
    p = p->sgt;
  }

  return cant;
}

void mostrarPila (TpLista p) {
  if (p == NULL) {
    cout << "Nada para mostrar. (La pila esta vacia)" << endl;
    return;
  }
  int i = 1;
  while (p != NULL) {
    cout << i << ") Peso 2: " << p->pesoDos << endl;
    i++;
    p = p->sgt;
  }
}

TpLista pop (TpLista &p) {
  if (p == NULL) {
    cout << "La pila esta vacia." << endl;
    return NULL;
  }
  TpLista tmp = p;
  p = p->sgt;
  tmp->sgt = NULL;
  return tmp;
}

void insertarFinal (TpLista &ld, TpLista nodo) {
  TpLista tmp = nodo;
  TpLista track = ld;

  if (nodo == NULL) {
    return;
  }

  if (ld == NULL) {
    ld = nodo;
    return;
  }

  while (track->sgt != NULL) {
    track = track->sgt;
  }

  tmp->ant = track;
  track->sgt = tmp;
}

void mostrarListaDoble (TpLista ld) {
  int i = 1;
  TpLista ant;
  if (ld == NULL) {
    cout << "Lista Doblemente Enlazada vacía." << endl;
    return;
  }
  cout << "IDA" << endl;
  while (ld != NULL) {
    cout << i << ") Peso 2: " << ld->pesoDos << endl;
    i++;
    ant = ld;
    ld = ld->sgt;
  }

  cout << "VUELTA" << endl;
  i--;
  ld = ant;
  while (ld != NULL) {
    cout << i << ") Peso 2: " << ld->pesoDos << endl;
    ld = ld->ant;
    i--;
  }
}

void mostrarListaDobleCompleta (TpLista ld) {
  int i = 1;
  TpLista ant;
  if (ld == NULL) {
    cout << "Lista Doblemente Enlazada vacía." << endl;
    return;
  }
  cout << "IDA" << endl;
  while (ld != NULL) {
    cout << i << ") Peso 1: " << ld->pesoUno << " || Peso 2: " << ld->pesoDos << " || Peso 3: " << ld->pesoTres << endl;
    i++;
    ant = ld;
    ld = ld->sgt;
  }

  cout << "VUELTA" << endl;
  i--;
  ld = ant;
  while (ld != NULL) {
    cout << i << ") Peso 1: " << ld->pesoUno << " || Peso 2: " << ld->pesoDos << " || Peso 3: " << ld->pesoTres << endl;
    ld = ld->ant;
    i--;
  }
}

void asignarPesos (TpLista &ld) {
  if (ld == NULL) {
    cout << "Lista Doblemente Enlazada vacía." << endl;
    return;
  }

  TpLista track = ld, ant;
  cout << "IDA" << endl;
  while (track != NULL) {
    track->pesoUno = generarNumero(10, 20);
    ant = track;
    track = track->sgt;
  }

  cout << "VUELTA" << endl;
  track = ant;
  while (track != NULL) {
    track->pesoTres = generarNumero(30, 50);
    track = track->ant;
  }
}

void filtrar (TpLista &ld) {
  int i = 1;
  TpLista tmp = ld, copy;
  cout << "Se eliminaran: " << endl;
  while (tmp != NULL) {
    if (tmp->pesoUno + tmp->pesoDos + tmp->pesoTres > 75) {
      cout << i << ") Peso 1: " << tmp->pesoUno << " || Peso 2: " << tmp->pesoDos << " || Peso 3: " << tmp->pesoTres << endl;
      copy = tmp;
      tmp = tmp->sgt;
      eliminarDato(ld, copy->pesoUno, copy->pesoDos, copy->pesoTres);
      i++;
    } else {
      tmp = tmp->sgt;
    }
  }
}

void eliminarDato (TpLista &ld, int uno, int dos, int tres) {
  TpLista toDelete = ld;
  while (!(toDelete->pesoUno == uno || toDelete->pesoDos == dos || toDelete->pesoTres ==  tres)) {
    toDelete = toDelete->sgt;
  }

  // Si es el primero
  if (toDelete == ld) {
    ld = ld->sgt;
    if (ld != NULL) {
      ld->ant = NULL;
    }
    delete toDelete;
    return;
  }

  TpLista ant = toDelete->ant;

  ant->sgt = toDelete->sgt;
  if (toDelete->sgt != NULL) {
    toDelete->sgt->ant = ant;
  }
  delete toDelete;
}

void menu (TpLista &ld, TpLista &p) {
  int opcion, position;
  do {
    cout << "------------------------------------------------------------------\n";
    cout << "1. Ingresar elemento en la pila.\n2. Descargar elemento de la Pila.\n3. Asignar pesos a Lista (ida - vuelta).\n4. Eliminar elemento.\n5. Mostrar Lista.\n";
    cin >> opcion;
    cout << "------------------------------------------------------------------\n";
    switch (opcion) {
      case 1:
        push(p);
        mostrarPila(p);
        break;
      case 2:
        insertarFinal(ld, pop(p));
        cout << "Pila" << endl;
        mostrarPila(p);
        cout << "Lista Doble" << endl;
        mostrarListaDoble(ld);
        break;
      case 3:
        asignarPesos(ld);
        mostrarListaDobleCompleta(ld);
        break;
      case 4:
        filtrar(ld);
        cout << "Lista Doble luego de eliminar" << endl;
        mostrarListaDobleCompleta(ld);
        break;
      case 5:
        mostrarListaDobleCompleta(ld);
        break;
    }
  } while (opcion >= 1 && opcion <= 7);
}

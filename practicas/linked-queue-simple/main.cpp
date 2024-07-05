#include <iostream>
#include <stdlib.h>
#include <time.h>

struct nodo{
  int dato;
  struct nodo *siguiente;
};

using namespace std;
typedef struct nodo *Lista;

int generarRandom();
void insertarInicio (Lista &, int);
void insertarFinal (Lista &, int);
void insertar(Lista &);
void mostrar(Lista);
void cantidad(Lista);
void buscarMayor(Lista);
void buscarMenor(Lista);
void promediar(Lista);
void menu (Lista &);

int main () {
  Lista inicio = NULL;
  srand(time(NULL)); 
  menu(inicio);
  return 0;
}

int generarRandom () {
  int ran = 0;
  do{
    ran = -200 + rand() % 401;
  } while (ran == 0);
  return ran;
}

void insertarInicio (Lista &l, int dato) {
  Lista tmp = new(struct nodo);
  tmp->dato = dato;
  tmp->siguiente = l;
  l = tmp;
}

void insertarFinal (Lista &l, int dato) {
  Lista tmp = new(struct nodo);
  Lista final = l;
  tmp->dato = dato;
  tmp->siguiente = NULL;
  while (final->siguiente != NULL) {
    final = final->siguiente;
  }
  final->siguiente = tmp;
}

void insertar (Lista &l) {
  int ran = generarRandom();
  if (l == NULL) {
    l = new(struct nodo);
    l->dato = ran;
    l->siguiente = NULL;
  } else {
    if (ran > 0) {
      insertarFinal(l, ran);
    } else {
      insertarInicio(l, ran);
    }
  }
}

void mostrar (Lista l) {
  int index = 0;
  cout << "----------------------------------------------------------------\n";
  while (l != NULL) {
    cout << index + 1 << " : " << l->dato << endl;
    l = l->siguiente;
    index++;
  }
  cout << "-----------------------------------------------------------------\n";
}

void cantidad (Lista l) {
  int cant = 0;
  while (l != NULL) {
    cant++;
    l = l->siguiente;
  }
  cout << "-----------------------------------------------------------------\n";
  cout << "La lista tiene " << cant << " elementos.\n";
  cout << "-----------------------------------------------------------------\n";
}

void buscarMayor (Lista l) {
  int mayor = l->dato;
  int pos = -1;
  int index = 1;
  while (l != NULL) {
    if (mayor <= l->dato) {
      mayor = l->dato;
      pos = index;
    }
    index++;
    l = l->siguiente;
  }
  cout << "El mayor elemento es: " << mayor << " || Esta en la posicion: " << pos << endl;
}

void buscarMenor (Lista l) {
  int menor = l->dato;
  int pos;
  int index = 1;
  while (l != NULL) {
    if (menor >= l->dato) {
      menor = l->dato;
      pos = index;
    }
    index++;
    l = l->siguiente;
  }
  cout << "El menor elemento es: " << menor << " || Esta en la posicion: " << pos << endl;
}
void promediar (Lista l) {
  // float para que salga con decimales
  float suma = 0;
  float cantidad = 0;
  while (l != NULL) {
    suma += l->dato;
    l = l->siguiente;
    cantidad++; 
  }
  cout << "-----------------------------------------------------------------\n";
  cout << "El promedio de los elementos de la lista es: " << suma/cantidad << endl;
  cout << "-----------------------------------------------------------------\n";
}

void menu (Lista &l) {
  int opcion;
  do {
    cout << "Escoja una opcion a realizar con la lista enlazada: \n1. Agregar numero.\n2. Mostrar.\n3. Cantidad de elementos.\n4. Mostrar mayor y menor elemento.\n5. Promedio de los elementos de la lista.\n";
    cin >> opcion;
    switch (opcion) {
      case 1:
        insertar(l);
        mostrar(l);
        break;
      case 2:
        mostrar(l);
        break;
      case 3:
        cantidad(l);
        break;
      case 4:
        cout << "-----------------------------------------------------------------\n";
        buscarMayor(l);
        buscarMenor(l);
        cout << "-----------------------------------------------------------------\n";
        break;
      case 5:
        promediar(l);
        break;
    }
  } while (opcion == 1 || opcion == 2 || opcion == 3 || opcion == 4 || opcion == 5);
}

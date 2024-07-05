#include <iostream>

#include "Persona.h"
#include "Array.h"

using namespace std;

void showMenu();
void createNew(Array&);

int main () {
  showMenu();
}

void showMenu () {
  int a;
  Array array = Array();
  do{
    cout << "-----------------------------------------\n";
    cout << "1. Añadir un elemento.\n2. Mostrar el array.\n3. Mostrar el primer elemento.\n4. Mostrar el último elemento.\n5. Ordenar por edad.\n* Cualquier otro para cerrar.\n";
    cin >> a;
    cout << "-----------------------------------------\n";
    switch (a) {
      case 1:
        createNew(array);
        break;
      case 2:
        array.showArray();
        break;
      case 3:
        array.shift().showPerson();
        break;
      case 4:
        array.pop().showPerson();
        break;
      case 5:
        array.sortByAge();
        break;
    }
  } while (a == 1 || a == 2 || a == 3 || a == 4 || a == 5);
}

void createNew (Array& a) {
  string name;
  int age;
  cout << "Nombre: \n";
  cin >> name;
  cout << "Edad: \n";
  cin >> age;
  a.add(Persona(age, name));
}

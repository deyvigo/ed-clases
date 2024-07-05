#include <iostream>
#include <stdlib.h>
#include <time.h>

using namespace std;

class Array {
  private:
    int *arr;
    int index;
  public:
    Array();
    void show();
    void addNumber(int);
    int getIndex();
    int pop(); // delete and return last element
};

Array::Array () {
  arr = new int[10];
  index = 0;
}

void Array::show () {
  for (int i = 0; i < index; i++) {
    if (i + 1 == index) {
      cout << arr[i] << " ";
    } else {
      cout << arr[i] << " | ";
    }
  }
}

void Array::addNumber (int number) {
  if (index < 10) {
    int *tmp = new int[10];
    tmp[0] = number;
    for (int i = 0; i < index; i++) {
      tmp[i + 1] = arr[i];
    }
    delete[] arr;
    index++;
    arr = tmp;
  }
}

int Array::getIndex () {
  return index;
}

int Array::pop () {
  int element = arr[index-1];
  arr[index-1] = 0;
  index--;
  return element;
}

// functions
int getPairNumber ();
int getOddNumber ();
void menu (Array&, Array&, Array&);

int main () {
  Array even = Array();
  Array odd = Array();
  Array extractAddition = Array();

  menu(even, odd, extractAddition);

  return 0;
}

void menu (Array &even, Array &odd, Array &extractAddition) {
  int option;
  do {
    cout << "---------------------------------\n";
    cout << "1. Agregar numero.\n2. Eliminar numero.\n3. Mostrar elementos.\n";
    cin >> option;
    switch (option) {
      case 1:
        even.addNumber(getPairNumber());
        odd.addNumber(getOddNumber());
        break;
      case 2:
        extractAddition.addNumber(even.pop() + odd.pop());
        break;
      case 3:
        cout << "Numeros pares:   ";
        even.show();
        cout << endl;
        cout << "Numeros impares: ";
        odd.show();
        cout << endl;
        cout << "Vector C: ";
        extractAddition.show();
        cout << endl;
        break;
    }
  } while (option == 1 || option == 2 || option == 3);
}

int getPairNumber () {
  srand(time(NULL));
  int random;
  do { 
    random = rand() % 101;
  } while (random % 2 != 0 && random == 0);
  return random;
}

int getOddNumber () {
  srand(time(NULL));
  int random;
  do { 
    random = -100 + rand() % 101;
  } while (random % 2 == 0 && random == 0);
  return random;
}
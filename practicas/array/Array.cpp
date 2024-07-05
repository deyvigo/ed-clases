#include <iostream>

#include "Array.h"
#include "Persona.h"

using namespace std;

Array::Array () {
  index = 0;
  personas = new Persona[size];
}

bool Array::isFill () {
  return index >= size;
}

void Array::add (Persona p) {
  if (!isFill()){
    personas[index] = p;
    setIndex(index + 1);
  } else {
    increaseSize();
    personas[index] = p;
    setIndex(index + 1);
  }
}

void Array::showArray () {
  if (index <= 0) {
    cout << "Array vacío.\n";
  } else {
    for (int i = 0; i < index; i++){
      cout << i << " || ";
      personas[i].showPerson();
    }
  }
}

void Array::setIndex (int _index) {
  index = _index;
}

void Array::setSize (int _size) {
  size = _size;
}

void Array::increaseSize () {
  setSize(size + 1);
  cout << size << endl;
  Persona* temp = new Persona[size];
  for (int i = 0; i < index; i++){
    temp[i] = personas[i];
  }
  delete[] personas;
  personas = temp;
}

Persona Array::pop () {
  return personas[index-1];
}

Persona Array::shift () {
  return personas[0];
}

void Array::sortByAge () {
  Persona temp;
  for (int i = 0; i < index - 1; i++){
    for (int j = i; j < index; j++){
      if (personas[i].getAge() > personas[j].getAge()) {
        temp = personas[i];
        personas[i] = personas[j];
        personas[j] = temp;
      }
    }
  }
}

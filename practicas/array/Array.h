#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

#include "Persona.h"

using namespace std;

class Array {
  private:
    int index;
    int size = 2;
    Persona *personas;
  public:
    Array();
    void add(Persona p);
    bool isFill();
    void showArray();
    void setIndex(int _index);
    void increaseSize();
    void setSize(int _size);
    Persona pop();
    Persona shift();
    void sortByAge();
};

#endif // ARRAY_H
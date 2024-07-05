#include <iostream>

#include "Persona.h"

using namespace std;

Persona::Persona (int _age, string _name) {
  age = _age;
  name = _name;
}

Persona::Persona () {}

void Persona::showPerson () {
  cout << "Name: " << name << " || Age: " << age << endl;
}

int Persona::getAge () {
  return age;
}

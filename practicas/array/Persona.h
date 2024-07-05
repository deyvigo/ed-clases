#ifndef PERSONA_H
#define PERSONA_H

#include <iostream>

using namespace std;

class Persona {
  private:
    int age;
    string name;
  public:
    Persona();
    Persona(int, string);
    void showPerson();
    int getAge();
};

#endif // PERSONA_H
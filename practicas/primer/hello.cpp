#include <iostream>

#include "Persona.h"

using namespace std;

int main(){
  Persona p1 = Persona(20, "Deyvi");
  p1.showPerson();
  p1.setAge(24);
  p1.showPerson();
  return 0;
}
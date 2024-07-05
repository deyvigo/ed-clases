#include<iostream>

#include "Persona.h"
using namespace std;

Persona::Persona(int age, string name){
  this->age = age;
  this->name = name;
}

void Persona::showPerson(){
  cout << "Name: " << name << endl;
  cout << "Age: " << age << endl;
}

void Persona::setAge(int age){
  this->age = age;
}

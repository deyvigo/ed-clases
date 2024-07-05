#include <iostream>

using namespace std;

class Persona {
  private:
    int age;
    string name;
  public:
    Persona(int age, string name);
    void showPerson();
    void setAge(int age);
};
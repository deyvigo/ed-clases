#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "Node.h"

using namespace std;

class Stack {
  private:
    int capacity;
    Node *top;
  public:
    Stack();
    void push(Node&);
    Node *pop(); // delete and return element on top
    Node *peek(); // return element on top (last)
    void show();
};

#endif // STACK_H
#ifndef STACK_H
#define STACK_H

#include <iostream>

#include "Node.h"

using namespace std;

class Stack {
  private:
    Node *top;
    int capacity;
  public:
    Stack();
    void push(char);
    bool isEmpty();
    void show();
    Node &pop(); // delete and return top element
    Node &peek(); // only returns top element
};

#endif // STACK_H
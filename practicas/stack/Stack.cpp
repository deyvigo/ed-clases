#include "Stack.h"

Stack::Stack () {
  top = NULL;
  capacity = 0;
}

void Stack::push (Node &n) {
  n.setNext(*top);
  this->top = &n;
  this->capacity++;
}

void Stack::show () {
  Node *aux = this->top;
  while (aux != NULL) {
    aux->show();
    aux = aux->getNext();
  }
}

Node *Stack::peek () {
  return this->top;
}

Node *Stack::pop () {
  Node *aux = this->top;
  this->top = top->getNext();
  this->capacity--;
  return aux;
}
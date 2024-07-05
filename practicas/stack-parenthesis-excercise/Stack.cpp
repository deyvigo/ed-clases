#include "Stack.h"

Stack::Stack () {
  top = NULL;
  capacity = 0;
}

void Stack::push (char _data) {
  Node *node = new Node(_data);
  node->setNext(*top);
  top = node;
  capacity++;
}

bool Stack::isEmpty () {
  return capacity == 0;
}

Node &Stack::pop () {
  Node *aux = top;
  top = &top->getNext();
  capacity--;
  return *top;
}

void Stack::show () {
  Node *aux = this->top;
  while (aux != NULL) {
    cout << aux->getData() << endl;
    aux = &aux->getNext();
  }
}

Node &Stack::peek () {
  return *top;
}
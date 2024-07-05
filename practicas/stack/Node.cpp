#include "Node.h"

Node::Node (string _data) {
  data = _data;
  Node *next = NULL;
}

Node::Node () {
  next = NULL;
}

void Node::setNext (Node &n) {
  this->next = &n;
}

void Node::show () {
  cout << "Dato: " << data << endl;
}

Node *Node::getNext () {
  return this->next;
}
#include "Node.h"

Node::Node (char _data) {
  data = _data;
  next = NULL;
}

Node::Node () {}

char Node::getData () {
  return data;
}

void Node::setData (char _data) {
  data = _data;
}

void Node::setNext (Node &_next) {
  next = &_next;
}

Node &Node::getNext () {
  return *next;
}
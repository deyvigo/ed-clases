#include <iostream>

#include "Stack.h"
#include "Node.h"

int main () {
  Stack myStack = Stack();
  Node node = Node("Subaru");
  myStack.push(node);
  Node node2 = Node("Mitsubishi");
  myStack.push(node2);
  Node node3 = Node("Honda");
  myStack.push(node3);
  cout << "-------------------\n";
  myStack.show();
  cout << "Element on top: ";
  myStack.peek()->show();
  cout << "-------------------\n";
  cout << "Delete element from Stack: ";
  myStack.pop()->show();
  myStack.show();
}
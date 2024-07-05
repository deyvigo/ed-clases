#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
  private:
    string data;
    Node *next;
  public:
    Node(string);
    Node();
    void setNext(Node&);
    Node *getNext();
    void show();
};

#endif // NODE_H
#ifndef NODE_H
#define NODE_H

#include <iostream>

using namespace std;

class Node {
  private:
    char data;
    Node *next;
  public:
    Node(char);
    Node();
    char getData();
    void setData(char);
    Node &getNext();
    void setNext(Node &);
};

#endif // NODE_H
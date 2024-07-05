/*
Paréntesis balanceados
Ejemplo:
  ()(() -> false
  (()()) -> true
*/

#include <iostream>
#include <string>

#include "Stack.h"

int main () {
  string combination;
  cout << "Digite una combinación de paréntesis: " << endl;
  cin >> combination;
  const int length = combination.length();
  Stack stack = Stack();

  for (int i = 0; i < length; i++) {
    if (combination[i] == '(') {
      stack.push('(');
    } else if (combination[i] == ')') {
      stack.pop();
    }
  }

  cout << "-------------------------------------------------\n";
  
  if (stack.isEmpty()) {
    cout << "Los paréntesis están balanceados\n";
  } else {
    cout << "Los paréntesis NO están balanceados\n";
  }

  return 0;

  // stack.push('1');
  // stack.push('2');
  // stack.push('3');
  // stack.push('4');
  // stack.push('5');
  // cout << "Element on top : ";
  // cout << stack.peek().getData() << endl;
  // cout << "---------------------------" << endl;
  // stack.show();
  // stack.pop();
  // cout << "---------------------------" << endl;
  // stack.pop();
  // stack.pop();
  // stack.show();
  // cout << "---------------------------" << endl;
  // cout << "Element on top : ";
  // cout << stack.peek().getData() << endl;
}


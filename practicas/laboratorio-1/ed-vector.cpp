#include <iostream>

using namespace std;

int main () {
  int *arr = new int[10];
  for (int i = 0; i < 9; i++) {
    arr[i] = i;
  }
  int *tmp = new int[10];
  cout << arr << endl;
  for (int i = 0; i < 9; i++) {
    cout << arr[i] << " | ";
    tmp[i] = i + 3;
  }
  cout << endl;
  arr = tmp;

  for (int i = 0; i < 9; i++) {
    cout << arr[i] << " | ";
  }
  cout << endl;

  return 0;
}

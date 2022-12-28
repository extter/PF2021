#include <iostream>
int isqrt(int &n) {
  int i = 1;
  while (i * i < n) {
    ++i;
  }
  if (i * i > n) {
    --i;
  }
  return i;
}
int main() {
  std::cout << "Inserire il numero di cui si vuole calcolare la radice: ";
  int num;
  std::cin >> num;
  int i = isqrt(num);
  // qui sto chiamando/invocando la funzione che ho definito prima
  std::cout << i << '\n';
}
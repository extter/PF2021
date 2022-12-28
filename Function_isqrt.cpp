#include <iostream>
int isqrt(int n) {
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
  int n; // notare il fatto che qui ci poteva stare anche una variabile diversa,
         // per esempio num o altro, non è per forza necessario usare n ed i
  std::cin >> n;
  int i = isqrt(n);
  // qui sto chiamando/invocando la funzione che ho definito prima
  std::cout << i << '\n';
}
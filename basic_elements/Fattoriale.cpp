#include <iostream>
double fattoriale(int n) {
  double result = 1;
  for (int i = 0; i < n; ++i) {
    result = result * (n - i);
  }
  return result;
}
void print_fattoriale(int numero) {
  std::cout << "Il fattoriale di " << numero << " è " << fattoriale(numero)
            << '\n';
}
int main() {
  int n;
  std::cin >> n;
  print_fattoriale(n);
}

//problema grave: se metto un valore che non va bene, lui mi da come return 1, 
//ovvero errore. Soluzione: assert(?)
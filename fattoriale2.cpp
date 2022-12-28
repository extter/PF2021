#include <cstdlib>
#include <iostream>
using namespace std;
int fattoriale(int n) {
  int result = 1;
  for (int i = 0; i < n; ++i) {
    result = result * (n - i);
  }
  return result;
}
int main() {
  int numero;
  cout << "Inserisci numero di cui vuoi sapere il fattoriale:" << '\n';
  cin >> numero;
  if (cin.fail() || numero < 0) {
    cerr << "Non hai messo un numero" << '\n';
    return EXIT_FAILURE;
  }
  cout << fattoriale(numero) << '\n';
}
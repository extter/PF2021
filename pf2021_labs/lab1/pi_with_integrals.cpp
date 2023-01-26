#include <iostream>

int main() {
  const double estr_inf = 0.0;
  const double estr_sup = 1.0;
  int n;
  std::cout << "numero di intervalli:";
  std::cin >> n;
  const double deltax = (estr_sup - estr_inf) / n;
  double Area = 0.0;
  for (int i = 0; i < n; ++i) {
    double deltaxi = deltax * i;
    double deltayi = 4.0 / (1.0 + deltaxi * deltaxi);
    Area = Area + (deltax * deltayi);
  }
  std ::cout << "Pi Greco = " << Area << "\n";
}
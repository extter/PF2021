#include <iostream>
#include <string>
double pwd(double base, int esponente) {

  if (base == 0 && esponente == 0) {
    std::cout << "Errore: 0^0 non si può fare!";
    std::string s = "meglio riprovare";
    std::cout<< s;
  } else {
    double t = 1;
    for (int i = 0; i < esponente; i++) {
      t = t * base;
    }
    return t;
  };
};

int main() {
  double a;
  int b;
  std::cin >> a >> b;
  std::cout << pwd(a, b) << '\n';
}
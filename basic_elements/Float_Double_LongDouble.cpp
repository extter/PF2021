#include <float.h>
#include <iostream>

int main() {
  float a = 3.0;
  double b = 3.0;
  long double c = 3.0;

  std::cout << std::fixed << (a / 2) * 1000000000000 << '\n';
  //il comando std::fixed prende un numero e lo mette in forma x.xxxxxxxxxx, mentre
  //il comando std::scientific lo mette in notazione scientifica.
  std::cout << FLT_DIG << '\n';
  // mi fa vedere quante sono le cifre significative del float,
  // ovvero 6. Dalla settima in poi, non hanno più senso
  std::cout << std::fixed << (b / 2) * 1000000000000 << '\n';
  std::cout << DBL_DIG << '\n';
  std::cout << std::fixed << (c / 2) * 1000000000000 << '\n';
  std::cout << LDBL_DIG << '\n';
}
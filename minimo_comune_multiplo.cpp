#include <iostream>
int mcm(int a, int b) {
  if (a == 0) {
    return 0;
  }
  if (b == 0) {
    return 0;
  }
  if (a == b) {
    return a;
  } else {
    int n; // ia == nb, dunque i = n(b/a)
    for (int i = 1; i < b + 1; ++i) {
      for (n = 1; n < a + 1; ++n) {
        if ((n * b) % a == 0) {
          return n * b;
        }
      };
    }
  }
}
int main() {
  int a;
  int b;
  std::cout << "Inserire i due numeri: " << '\n';
  std::cin >> a >> b;
  std::cout << mcm(a, b) << '\n';
}
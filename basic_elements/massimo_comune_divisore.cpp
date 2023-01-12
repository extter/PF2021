#include <iostream>
int mcd(int a, int b) {
  while (b != 0) {
    int const t = a;
    a = b;
    b = t % b;
  }
  return a;
}
int main() {
  int a;
  int b;
  std::cin >> a >> b;
  std::cout << mcd(a, b) << '\n';
}
#include <iostream>

int main() {
  char i;
  std::cin >> i;
  bool condizione = i > 64 && i < 91;

  if (condizione == true) {
    i = std::tolower(i);
    std::cout << i << '\n';
    ;
  } else {
    std::cout << i << '\n';
  }
}
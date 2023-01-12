#include <iostream>
#include <random>

int main() {
  std::default_random_engine gen;
  for (int i = 0; i < 100000; ++i) {
    std::cout << gen() << '\n';
  };
}
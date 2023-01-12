#include <iostream>
#include <random>
int main() {
  std::default_random_engine gen;
  std::uniform_real_distribution<double> random_position(0., 1.);

  double a = random_position(gen);
  double b = random_position(gen);
  double c = random_position(gen);

  std::cout << a << '\n';
  std::cout << b << '\n';
  std::cout << c << '\n';
}
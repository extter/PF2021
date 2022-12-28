#include <iostream>
#include <random>

int main() {
  /////////////////////////////////////////////////////////////
  {
    std::default_random_engine gen;
    std::normal_distribution<float> distrib; // mean = 0. & std distrib = 1.
    for (int i = 1; i < 10; ++i) {
      std::cout << distrib(gen) << '\n';
    };
  }
  ////////////////////////////////////////////////////////////
  {
    std::default_random_engine gen;
    std::uniform_int_distribution<> distrib;
    for (int i = 1; i < 10; ++i) {
      std::cout << distrib(gen) << '\n';
    };
  }
  ////////////////////////////////////////////////////////////
}
#include "chain.hpp"

#include <iostream>
#include <stdexcept>

int main() {
  try {
    double k;
    double l;

    std::cout << "Insert elastic k:\n";
    std::cin >> k;
    std::cout << "Insert initial lenght l:\n";
    std::cin >> l;
    Hooke molla{k, l};

  } catch (std::runtime_error const& e) {
    std::cerr << e.what() << '\n';
  };
}
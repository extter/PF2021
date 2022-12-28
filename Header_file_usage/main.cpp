#include "hello.hpp"
//#include <iostream>
//#include <string>

// void hello(std::string const &a) { std::cout << "Ciao," << a << '\n'; }

int main() {
  std::string nome;
  std::cin >> nome;
  hello(nome);
}
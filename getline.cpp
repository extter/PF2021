#include <iostream>
#include <string>

int main() {
  std::string stringa_input;
  getline(std::cin,
          stringa_input); // se faccio solo cin >> stringa_input, lui mi prende
                          // solo la prima parola perché si ferma allo spazio.
  std::cout << stringa_input << '\n';
}
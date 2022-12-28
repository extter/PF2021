// compile with: g++ -Wall -Wextra -g -fsanitize=address -std=c++17
// word_counting.cpp run with: ./a.out < divina_commedia.txt

#include <fstream>
#include <iomanip>
#include <iostream>
#include <map>

int main() {
  std::map<std::string, int> words;

  std::string const filename{"divina_commedia.txt"};

  // sennò metto filename{argv[1]}, e poi faccio a.out < divina......

  std::ifstream is{filename};

  if (!is) {
    std::cerr << "Cannot open file";
  }

  std::string word;

  while (is >> word) {
    ++words[word];
  }

  is.close();

  // lo faccio qui, sennò il compilatore lo avrebbe fatto alla fine
  // sennò metto le parentesi graffe per chiudere quella parte, così creo da
  // solo uno scope e tutto muore quando finisce

  auto const width = 12; // larghezza max parola: 6
  for (auto const &[w, c] : words) {
    std::cout << std::setw(width) << std::left << w << ": " << std::setw(6)
              << std::right << c << '\n';
  }
}
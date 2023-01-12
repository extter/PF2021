#include <algorithm>
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

void print_ordinals(std::vector<std::size_t> const &ordinals) {
  std::cout << "ordinals: ";
  for (std::size_t ord : ordinals)
    std::cout << std::setw(3) << ord << ' ';
  std::cout << '\n';
}

int main() {
  std::string s{"hello"};
  std::transform(s.begin(), s.end(),
                 s.begin(), // write to the same location
                 [](unsigned char c) { return std::toupper(c); });
  std::cout << "s = " << quoted(s) << '\n';

  // achieving the same with std::for_each
  std::string g{"hello"};
  std::for_each(g.begin(), g.end(), [](char &c) {
    c = std::toupper(static_cast<unsigned char>(c));
  });
  std::cout << "g = " << quoted(g) << '\n';

  // creo un vettore che contiene gli integer dei caratteri di Hello; il back
  // inserter ci deve essere perché non metto la size che ha ordinals, e se
  // metto al suo posto ordinals.begin(), mi dà segmentation fault, poiché
  // ordinals non ha capacity.
  std::vector<std::size_t> ordinals;
  std::transform(s.begin(), s.end(), std::back_inserter(ordinals),
                 [](unsigned char c) { return c; });

  print_ordinals(ordinals);

  // transform può anche essere usata su due range (se uso una funzione che
  // prende due parametri e non uno). qui prendo ordinals e sovrascrivo il
  // doppio di ogni elemento di ordinals; terzo argomento -> inizio secondo
  // range; quarto argomento -> inizio range d'arrivo
  std::transform(ordinals.begin(), ordinals.end(), ordinals.begin(),
                 ordinals.begin(), std::plus<>{});

  print_ordinals(ordinals);
}
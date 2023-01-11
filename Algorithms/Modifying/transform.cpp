#include <algorithm>
#include <cctype>
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
  std::transform(s.cbegin(), s.cend(),
                 s.begin(), // write to the same location
                 [](unsigned char c) { return std::toupper(c); });
  std::cout << "s = " << quoted(s) << '\n';

  // achieving the same with std::for_each (see Notes above)
  std::string g{"hello"};
  std::for_each(g.begin(), g.end(),
                [](char &c) // modify in-place
                { c = std::toupper(static_cast<unsigned char>(c)); });
  std::cout << "g = " << quoted(g) << '\n';

  std::vector<std::size_t> ordinals;
  std::transform(s.cbegin(), s.cend(), std::back_inserter(ordinals),
                 [](unsigned char c) { return c; });

  print_ordinals(ordinals);

  std::transform(ordinals.cbegin(), ordinals.cend(), ordinals.cbegin(),
                 ordinals.begin(), std::plus<>{});

  print_ordinals(ordinals);
}
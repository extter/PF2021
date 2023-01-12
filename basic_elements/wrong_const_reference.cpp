#include <iostream>
#include <string>
using namespace std;

int main() {
  string const nome = "Catalin";
  // string &refnome = nome; giustamente dà errore, poiché dropping qualifiers;
  string const &refnome = nome;
  // refnome = refnome + " Sajin"; anche qui dà errore: cerco di cambiare il
  // letterale
  cout << '\t' << " Questo è nome: " << nome << '\n';
  cout << '\t' << " Questo è referenza al nome: " << refnome << '\n';
}
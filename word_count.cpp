#include <iostream>
#include <string>
using namespace std;

int main() {
  string stringa;
  getline(cin, stringa);
  string const& rstringa = stringa;
  int wordcount = 1;
  // poi dovrei usare forse un array sad:(
  // risoluzione fatta da me conta anche gli spazi messi a caso, o all'inizio, quindi errore!!!
  for (char c : rstringa) {
    if (c == ' ') {
      ++wordcount;
    }
  }
  cout << wordcount << '\n';
}
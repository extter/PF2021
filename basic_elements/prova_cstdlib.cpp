#include <cstdlib>
#include <iostream>
using namespace std; // mi permette di non usare ogni volta gli std:: ; invece
                     // basta solo mettere cin, cout, cerr ...

int main() {
  int n;
  cin >> n;
  if (cin.fail() || n < 0) {
    cerr << "Invalid number\n";
    return EXIT_FAILURE;
  }
}
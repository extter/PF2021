#include <iostream>
#include <string>
using namespace std;

int main() {
  string empty;
  string saluti = "Buongiorno";
  string alfabeto = "abcdefghijklmnopqrstuvwxyz";
  cout << empty << endl;
  cout << saluti << endl;
  cout << alfabeto[6] << endl; // output (6+1)esima lettera dell'alfabeto.
  cout << alfabeto.length() << '\n'; //.lenght() è un membro della classe delle stringhe, e va messo dopo la variabile della stringa.
}
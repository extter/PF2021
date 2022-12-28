#include <iostream>
using namespace std;
struct Complex {
  double r;
  double i;
};

// operazione assignment: già generata dal compilatore

bool operator==(Complex const &a, Complex const &b) {
  return a.r == b.r && a.i == b.i;
}

Complex operator+(Complex const &a, Complex const &b) {
  return Complex{a.r + b.r, a.i + b.i};
};

int main() {
  Complex c;
  cout << "Inserire qui il numero complesso desiderato: " << '\n';
  cin >> c.r >> c.i;
  cout << '\n' << "Il numero complesso è " << c.r << "+" << c.i << "i" << '\n';
  // proviamo delle operazioni
  cout << "Il doppio di c è: " << c.r + c.r << "+" << c.i + c.i << "i" << '\n';
}
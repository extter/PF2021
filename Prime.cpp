#include <iostream>
using namespace std;
int is_prime(int n) {
  int i = 2;
  int a = n % i;
  while (a != 0) {
    ++i;
  }
  return i;
}

int main() {
  cout << "Inserisci numero che si vuole esaminare: ";
  int n;
  cin >> n;
  int result = is_prime(n);
  cout << result;
}
#include <iostream>
using namespace std;
int main() {
  double a = 12345.6789;
  int b = static_cast<int>(a);
  cout << b << '\n';
  //in questi casi, lo static_cast tronca un numero, quindi no approx.
}
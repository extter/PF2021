#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
using namespace std;
int fattoriale(int n) {
  int result = 1;
  for (int i = 0; i < n; ++i) {
    result = result * (n - i);
  }
  return result;
}
TEST_CASE("Testing function") {
  CHECK(fattoriale(0) == 1);
  CHECK(fattoriale(1) == 1);
  CHECK(fattoriale(2) == 2);
  CHECK(fattoriale(3) == 6);
  CHECK(fattoriale(4) == 24);
}

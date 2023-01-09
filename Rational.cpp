#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <cassert>
#include <numeric>

class Rational {
  int n_;
  int d_;

public:
  Rational(int n = 0, int d = 1) : n_{n}, d_{d} {
    auto const g = std::gcd(n_, d_); //OK, gcd è stato messo in c++17, quindi basta compilarlo in maniera giusta e questo errore non ci sarà
    n_ /= g;
    d_ /= g;
    if (d_ < 0) {
      d_ = -d_;
      n_ = -n_;
    }
    assert((std::gcd(n_, d_) == 1 || std::gcd(n_, d_) == -1) && d_ > 0);
  }
  int num() const { return n_; }
  int den() const { return d_; }
};
bool operator==(Rational const &r1, Rational const &r2) {
  return r1.num() == r2.num() && r1.den() == r2.den();
};

TEST_CASE("Testing Rational class:") {
  Rational r0{};
  Rational r1{5};
  Rational r2{-3, 2};
  CHECK(r2.num() == -3);
  CHECK(r2.den() == 2);
  CHECK(Rational{2, 2} == Rational{1, 1});
  CHECK(Rational{25, 10} == Rational{50, 20});
  CHECK(Rational{25, 10}.num() == 5);
  CHECK(Rational{2, -2} == -1);
  //  Rational r4{1, 0}; con questo dentro, doctest fa crashare il test_case
}
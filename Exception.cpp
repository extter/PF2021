#include <iostream>
#include <numeric>
#include <stdexcept>
#include <string>
class Rational {
  int n_;
  int d_;

public:
  Rational(int n = 0, int d = 1) : n_{n}, d_{d} {
    if (d_ == 0) {
      throw std::runtime_error{
          "Denominator is 0"}; //è una eccezione E; se volessi usare solo la E,
                               // dovrei fare struct E {} all'inizio.
    }
    auto const g = std::gcd(n_, d_);
    n_ /= g;
    d_ /= g;
    if (d_ < 0) {
      d_ = -d_;
      n_ = -n_;
    }
  }
  int num() const { return n_; }
  int den() const { return d_; }
};
bool operator==(Rational const &r1, Rational const &r2) {
  return r1.num() == r2.num() && r1.den() == r2.den();
};

int main() {
  int a;
  int b;
  std::cin >> a >> b;
  Rational r{a, b};
  try {
    Rational r;
  } catch (std::runtime_error const &e) {
    std::cout << e.what() << '\n';
  }
  std::cout << "Il numero razionale è: " << r.num() << "/" << r.den() << '\n';
}
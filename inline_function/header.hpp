#ifndef HEADER_HPP
#define HEADER_HPP


#include <cassert>
#include <iostream>
#include <numeric>
class Rational {
  int num_;
  int den_;

public:
  Rational(int num, int den) : num_{num}, den_{den} {
    assert(den != 0);

    if (den < 0)
      num_ = -num;
    den_ = -den_;

    if (std::gcd(num, den) != 1) {
      num_ /= std::gcd(num, den);
      den_ /= std::gcd(num, den);
    };
  };
  int GetNum() const { return num_; };
  int GetDen() const { return den_; };
  void Print() const { std::cout << num_ << ')' << '/' << '(' << den_; };

  // tutti i metodi di questa funzione sono implicitamente inline !!!; quelli
  // invece che bisogna dichiarare inline sono quelli free!
};

inline int prodotto_num_per_den(Rational const &numerino) {
  return numerino.GetDen() * numerino.GetNum();
}


#endif
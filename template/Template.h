#ifndef TEMPLATE_H
#define TEMPLATE_H

#include <cassert>
#include <cmath>
template <typename FLOATING_NUMBER> class Complex {
  FLOATING_NUMBER real_;
  FLOATING_NUMBER imag_;

public:
  Complex(FLOATING_NUMBER real = 0, FLOATING_NUMBER imag = 0)
      : real_{real}, imag_{imag} {};
  inline FLOATING_NUMBER GetReal(Complex const &c) { return (*this).real_; }
  inline FLOATING_NUMBER GetImag(Complex const &c) { return (*this).imag_; }
  inline FLOATING_NUMBER norm2(Complex const &c) {
    return pow(GetReal(c), 2) + pow(GetImag(c), 2);
  }
  inline Complex<FLOATING_NUMBER> &
  operator+=(Complex<FLOATING_NUMBER> const &other) {
    real_ += other.GetReal();
    imag_ += other.GetImag();
  }
};

template <typename FLOATING_NUMBER> auto operator+(Complex<FLOATING_NUMBER> const &primo,
               Complex<FLOATING_NUMBER> const &secondo) {
  return Complex<FLOATING_NUMBER>{primo.GetReal() + secondo.GetReal(),
                                  primo.GetImag() + secondo.GetImag()};
}
#endif
#include "static.h"

int Complex::counter_ = 0;


/*Complex::Complex() {
  real_ = 0.;
  imag_ = 0.;
  ++counter_;
};*/
double Complex::GetReal() const { return real_; }
double Complex::GetImag() const { return imag_; }
int Complex::GetCounter() { return counter_; }

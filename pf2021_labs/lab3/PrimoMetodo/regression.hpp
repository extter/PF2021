#ifndef REGRESSION_HPP
#define REGRESSION_HPP
#include <stdexcept>

struct Result {
  double A;
  double B;
};

class Regression {
  int N_{};
  double sum_x_{};
  double sum_y_{};
  double sum_xy_{};
  double sum_x2_{};

 public:
  int size() const { return N_; }

  Result fit() const {
    if (N_ < 2) {
      throw std::runtime_error{"Not enough points to run a fit"};
    }
    double const d = N_ * sum_x2_ - sum_x_ * sum_x_;
    if (d == 0.) {
      throw std::runtime_error{"Trying to fit a vertical line"};
    }
    double const a = (sum_y_ * sum_x2_ - sum_x_ * sum_xy_) / d;
    double const b = (N_ * sum_xy_ - sum_x_ * sum_y_) / d;
    return {a, b};
  }
  void add(double x, double y);
  // non metterla nella parte privata !!!
};

inline auto fit(Regression const &reg) {
  // the following call would fail compilation if the fit method weren't const
  return reg.fit();
}
// funzione definita fuori dalla classe, ma nel hpp;
// mettere inline, sennò lui trova 2 volte questa funzione e quindi NON LINKA:
// error ld

inline void Regression::add(double x, double y) {
  ++N_;
  sum_x_ += x;
  sum_y_ += y;
  sum_xy_ += x * y;
  sum_x2_ += x * x;
}
// stessa cosa di prima: inline per dire al linker di prendere questa come
// funzione Regression::add , perché poi tutte le altre sono token-by-token.
#endif
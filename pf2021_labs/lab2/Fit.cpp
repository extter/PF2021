#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <cassert>

#include "doctest.h"

struct Result {
  double A{};
  double B{};
};

class Regression {
 private:
  int N_{0};
  double sum_x_{};
  double sum_y_{};
  double quadratic_sum_x_{};
  double multiplication_x_y_{};

 public:
  void add(double x, double y) {
    ++N_;
    sum_x_ += x;
    sum_y_ += y;
    quadratic_sum_x_ += x * x;
    multiplication_x_y_ += x * y;
  }
  Result fit() const {
    assert(N_ == 0);
    double const A =
        ((sum_y_ * quadratic_sum_x_) - (sum_x_ * multiplication_x_y_)) /
        (N_ * quadratic_sum_x_ - sum_x_ * sum_x_);
    double const B = (N_ * multiplication_x_y_ - sum_x_ * sum_y_) /
                     (N_ * quadratic_sum_x_ - sum_x_ * sum_x_);
    return {A, B};
  };
};

TEST_CASE("Testing regression") {
  Regression reg;
  reg.add(0., 1.);
  reg.add(1., 2.);
  auto result = reg.fit();
  CHECK(result.A == doctest::Approx(1.));
  CHECK(result.B == doctest::Approx(1.));
  Regression reg2;
  auto result2 = reg.fit();
  CHECK(result2.A == doctest::Approx(0.));
  CHECK(result2.B == doctest::Approx(0.));
}
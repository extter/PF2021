#include "regression.hpp"

#include <stdexcept>

int Regression::size() const {
  return points_.size();
}

void Regression::add(double x, double y) { points_.push_back({x, y}); }

Result Regression::fit() const {
  const int N = points_.size();

  if (N < 2) {
    throw std::runtime_error{"Not enough points to run a fit"};
  }
  double sum_x{};
  double sum_y{};
  double sum_xy{};
  double sum_x2{};
  for (auto const& p : points_) {
    sum_x += p.x;
    sum_y += p.y;
    sum_xy += p.x * p.y;
    sum_x2 += p.x * p.x;
  }

  double const d = N * sum_x2 - sum_x * sum_x;
  if (d == 0.) {
    throw std::runtime_error{"Trying to fit a vertical line"};
  }

  
  double const a = (sum_y * sum_x2 - sum_x * sum_xy) / d;
  double const b = (N * sum_xy - sum_x * sum_y) / d;

  return {a, b};
}

Result fit(Regression const& reg) {
  // the following call would fail compilation if the fit method weren't const
  return reg.fit();
}

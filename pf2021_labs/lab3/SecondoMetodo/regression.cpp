#include "regression.hpp"

void Regression::add(double x, double y) {
  ++N_;
  sum_x_ += x;
  sum_y_ += y;
  sum_xy_ += x * y;
  sum_x2_ += x * x;
}
// qui non ci va l'inline, poiché tanto poi c'è solo una volta la funzione, ed è
// dichiarata solo una volta nel hpp
Result fit(Regression const &reg) { return reg.fit(); }
// non devo mettere auto, bensì result, poichè poi mi dice che faccio una cosa
// ambigua
#ifndef REGRESSION_HPP
#define REGRESSION_HPP
#include <vector>

struct Result {
  double A;
  double B;
};

class Regression {
  struct Point {
    double x;
    double y;
  };
std::vector<Point> points_{};
// ora devo controllare l'invariante di classe, dato che ho cambiato 
// delle cose dentro la parte privata.
// points_.size() è uguale a N ?
// i vari campi delle sommatorie devono essere calcolabili dai punti del vector
//int N_{};


 public:
  int size() const;
  void add(double x, double y);
  Result fit() const;
};

Result fit(Regression const &reg);

#endif

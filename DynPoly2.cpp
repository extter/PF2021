#include <algorithm>
#include <iostream>
#include <random>
#include <vector>
struct Shape {
  virtual ~Shape() = default;
  virtual void what() const = 0;
};
struct Circle : Shape {
  ~Circle() = default;
  void what() const override { std::cout << "circle"; }
};
struct Rectangle : Shape {
  ~Rectangle() = default;
  void what() const override { std::cout << "rectangle"; }
};

std::default_random_engine eng; // genera bit casuali / entropia
std::uniform_int_distribution<int>
    dist(0, 1); // do' quei bit casuali ad una distribuzione

Shape *create_shape() {
  if (dist(eng) == 0) {
    return new Circle;
  } else {
    return new Rectangle;
  }
};

int main() {
  std::vector<Shape *> shapes(10);
  std::generate_n(shapes.begin(), shapes.size(), create_shape);
  for (auto const &s : shapes) {
    s->what();
    std::cout << "\n";
  }
  for (auto const &s : shapes) {
    delete s;
  }
}
// le delete si mettono con un loop alla fine
// non mettendo il distruttore virtuale, la chiamata va a quello di Shape, e non passa attraverso il delete di circle, tuttavia 
// l'address sanitizer non riesce a vedere l'errore.
// il distruttore DEVE essere virtuale, se la funzione è virtuale
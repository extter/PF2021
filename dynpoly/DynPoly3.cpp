#include <algorithm>
#include <iostream>
#include <memory>
#include <random>
#include <vector>
struct Shape {
  virtual ~Shape() = default; // non devo mettere =0 sul distruttore, poiché il
                              // distruttore di rectangle e quello di circle
                              // hanno poi bisogno del distruttore di shape
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

std::default_random_engine eng; // genera bit casuali, tipo l'entropia
std::uniform_int_distribution<int>
    dist(0, 1); // do' quei bit casuali ad una distribuzione

std::unique_ptr<Shape> create_shape() {
  if (dist(eng) == 0) {
    return std::make_unique<Circle>();
  } else {
    return std::make_unique<Rectangle>();
  }
};

int main() {
  // std::vector<std::unique_ptr<Shape>> shapes(10);
  // in quel modo sto facendo un vettore di 10 elementi, poi sovrascrivo;
  // ora faccio un vettore vuoto invece

  std::vector<std::unique_ptr<Shape>> shapes;
  shapes.reserve(10);
  // size è sempre 0, ma ora ha una capacity di 10; ho allocato spazion

  // qui a sto punto devo usare il back inserter: è una funzione che genera un
  // back insert iterator; quando ci faccio *it = ..., quello viene convertito
  // in shapes.pushback
  // back inserter: è una funziona che genera questo iteratore speciale
  std::generate_n(std::back_inserter(shapes), shapes.capacity(), create_shape);
  for (auto const &s : shapes) {
    s->what();
    std::cout << "\n";
  }
}
// se tolgo il const &s, sto facendo una copia -> errore, perché è un unique_ptr

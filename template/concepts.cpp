#include <concepts> //C++20

template <class T> concept Incrementable = requires(T &t) { ++t; };

template <typename Incrementable> Incrementable funzione(Incrementable n) {
  return ++n;
};
int main() {
  int c = 5;
  return funzione(c);
}
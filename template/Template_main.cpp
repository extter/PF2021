#include "Template.h"

int main() {
  Complex<float> c{};
  Complex<double> d{};
  c = c + d; //non funziona poiché nell'.h ho definito l'operator+ come funzione che prende due oggetti complex omogenei :(
}
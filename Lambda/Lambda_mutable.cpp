int main() {

  // Target: ho un numero, n, e voglio modificarlo.

  int n;
  auto lambda = [&n]() { ++n; }; // o modifico attraverso la reference
  auto lambda_mutable = [n]() mutable -> void { ++n; };
  // oppure attraverso la mutable
}
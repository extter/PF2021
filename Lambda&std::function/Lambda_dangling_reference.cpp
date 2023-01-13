auto make_lambda() {
  int v = 3;
  return [&] { return v; };
}

int main() {
  auto lam = make_lambda();
  auto d = lam();
//here i created a dangling reference, since the variable v exists only in the make_lambda's block scope, while
//im trying to get it by reference with the return statement in the lambda block.
}
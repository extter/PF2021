/*class Classe_equivalente_lambda {
    int n_;

   public:
    explicit Classe_equivalente_lambda(int n) : n_{n} {};
    bool operator()(int comparison_value) { return comparison_value < n_; }
};*/

int main() {
  int comparison_value = 10;
  auto lambda = [comparison_value](int n) ->bool { return comparison_value < n; };
  return lambda(13);

  // è la stessa cosa dello scrivere :
  /*
  Classe_equivalente_lambda c{comparison_value};
  c(13);
  */
}
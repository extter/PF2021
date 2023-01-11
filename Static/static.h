class Complex {
  double real_;
  double imag_;
  static int counter_;

public:
Complex(double real = 0., double imag = 0.)
      : real_{real}, imag_{imag} {
    ++counter_;
  };
  // Complex();
  double GetReal() const;
  double GetImag() const;
  static int GetCounter();
};
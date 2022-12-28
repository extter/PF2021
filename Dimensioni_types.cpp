#include <climits> //non serve per sizeof;
#include <iostream>
int main() {
  std::cout << sizeof(short)
            << '\n'; // questo mi da in output il numero di byte (8 bit) di
                     // questo tipo di integral number. sizeof è un operatore.
  std::cout << SHRT_MIN
            << '\n'; // numero minimo che si può otterene con quel type
  std::cout << SHRT_MAX << '\n';
  std::cout << sizeof(long long)<<'\n';
  std::cout << LONG_LONG_MIN << '\n';
  std::cout << LONG_LONG_MAX << '\n';
  std::cout << sizeof(long)<<'\n';
  std::cout << LONG_MAX << '\n';
  std::cout << LONG_MIN << '\n';
  std::cout << INT64_MIN << '\n';
  std::cout << INT64_MAX << '\n';
}

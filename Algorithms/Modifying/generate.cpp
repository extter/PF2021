#include <algorithm>
#include <iostream>
#include <vector>

int f() {
  static int i;
  return ++i;
}

int main() {
  std::vector<int> v(5);
  auto print = [&] {
    for (std::cout << "v: "; auto iv : v)
      std::cout << iv << " ";
    std::cout << "\n";
  };

  std::generate(v.begin(), v.end(), f);
  print();

  // Initialize with default values 0,1,2,3,4 from a lambda function
  // Equivalent to std::iota(v.begin(), v.end(), 0);
  std::generate(v.begin(), v.end(), [n = 0]() mutable { return n++; });
  print();
}
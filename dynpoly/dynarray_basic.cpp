#include <algorithm>
#include <memory> //per gli unique_ptr e shared_ptr
class DynamicArray {
  int size_;
  int *data_;

public:
  // normal constructor
  DynamicArray(int size, int value = 0) : size_{size}, data_{new int[size_]} {
    std::fill(data_, data_ + size_, value);
  }
  // destructor
  ~DynamicArray() { delete[] data_; }
  // copy constructor
  DynamicArray(DynamicArray const &other)
      : size_{other.size_}, data_{new int[size_]} {
    std::copy(other.data_, other.data_ + other.size_, data_);
  }
  // copy assignment
  DynamicArray &operator=(DynamicArray const &other) {
    if (this != &other) {
      delete[] data_;
      size_ = other.size_;
      data_ = new int[size_];
      std::copy(other.data_, other.data_ + other.size_, data_);
    };
    return *this;
  }
};

int main() {
  DynamicArray b{5};    // normal constructor
  DynamicArray c{5, 0}; // normal constructor, filled
  auto d = c;           // copy constructor
  d = b;                // copy assignment

  std::unique_ptr<DynamicArray> p{
      new DynamicArray{5, 8}}; // ora è lui che tiene dentro l'oggetto;
  // not copiable !!!; i cant do auto pointer = p;
  auto p_released =
      p.release(); // unique ptr ha rilasciato la sua risorsa e non esiste
                   // più, ora ho un pointer che devo gestire io
  delete p_released;

  auto q_unique = std::make_unique<DynamicArray>(
      10, 3); // meglio; prende i parametri dalle parentesi e le mette
              // all'interno del costruttore di DynArr
}
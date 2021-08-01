#include <iostream>
#include "int_array.h"


// rather than using "static" on a free function for static linkage,
// in c++, put your top-level but "private" functions in the anonymous
// namespace. That's just a namespace with no name.
namespace {

int sum(const dsc::IntArray& array) {
  int total = 0;
  for (std::size_t i = 0; i < array.size(); ++i) {
    total += array[i];
  }
  return total;
}

void print_all(const dsc::IntArray& array) {
  for (std::size_t i = 0; i < array.size(); ++i) {
    std::cout << array[i] << '\n';
  }
}

} // namespace

int main() {
  dsc::IntArray array(6);
  array[0] = 3;
  array[1] = 6;
  array[2] = 20;
  array[3] = 40;
  array[4] = 100;
  array[5] = 200;

  print_all(array);

  std::cout << "sum = " << sum(array) << '\n';
}
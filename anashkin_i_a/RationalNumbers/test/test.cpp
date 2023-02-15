#include "test.hpp"

int& f(int k) {
  int a = k;
  return a;
}

int main() {
  int b = f(4);
  std::cout << b;
  return 0;
}
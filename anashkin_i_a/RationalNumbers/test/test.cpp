#include "test.hpp"

int f() {
  int a = 2;
  return a += 1;
}

int main() {
  std::cout << f();
  return 0;
}
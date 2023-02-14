#include "Rational.hpp"

int Rational::Gcd(int a, int b) {
  return b ? Rational::Gcd(b, a % b) : a;
}

Rational::Rational(int m, int n) {
  devisible = m;
  devider = n;
  int gcd = Gcd(m, n);
  devider /= gcd;
  devisible /= gcd;
}


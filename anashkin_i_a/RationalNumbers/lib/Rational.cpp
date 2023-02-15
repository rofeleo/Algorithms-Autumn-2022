#include "Rational.hpp"

int Rational::Gcd(int a, int b) {
  return b ? Rational::Gcd(b, a % b) : a;
}

/*
int Rational::Lcm(int a, int b) {
  return (a * b) / Gcd(a, b);
}
*/

Rational::Rational(int m, int n) {
  devisible = m;
  devider = n;
  int gcd = Gcd(m, n);
  devider /= gcd;
  devisible /= gcd;
}

Rational& Rational::operator+=(const Rational& rhs) {
  devisible = rhs.devisible * devider + devisible * rhs.devider;
  devider *= rhs.devider;
  return *this;
}

Rational& Rational::operator*=(const Rational& rhs) {
  devider *= rhs.devider;
  devisible *= rhs.devisible;
  return *this;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
  ostrm << devisible << devide << devider;
  return ostrm;
}

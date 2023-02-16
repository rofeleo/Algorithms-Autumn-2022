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

Rational& Rational::operator-=(const Rational& rhs) {
  devisible = rhs.devisible * devider - devisible * rhs.devider;
  devider *= rhs.devider;
  return *this;
}

std::ostream& Rational::WriteTo(std::ostream& ostrm) const {
  ostrm << devisible << devide << devider;
  return ostrm;
}

std::istream& Rational::ReadFrom(std::istream& istrm) {
  int m, n;
  char devide;
  istrm >> m >> devide >> n;
  if (istrm.good()) {
    if (Rational::devide == devide) {
      devisible = m;
      devider = n;
    } else {
      istrm.setstate(std::ios_base::failbit);
    }
  }
  return istrm;
}

Rational operator-(const Rational& lhs, const Rational& rhs) {
  Rational sum = lhs;
  sum -= rhs;
  return sum;
}

Rational operator+(const Rational& lhs, const Rational& rhs) {
  Rational sum = lhs;
  sum += rhs;
  return sum;
}

Rational operator*(const Rational& lhs, const Rational& rhs) {
  Rational mul = lhs;
  mul *= rhs;
  return mul;
}

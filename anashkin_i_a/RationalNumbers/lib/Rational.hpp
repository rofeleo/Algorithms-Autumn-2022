#include <iostream>
#include <sstream>

class Rational
{
public:
  Rational() {}
  explicit Rational(const int m, const int n);
  bool operator==(const Rational& rhs) const { return (devider == rhs.devider) && (devisible == rhs.devisible); }
  bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
  Rational& operator+=(const Rational& rhs);
  Rational& operator+=(const int rhs) { return operator+=(Rational(rhs, 1)); }
  Rational& operator-=(const Rational& rhs);
  Rational& operator-=(const int rhs) { return operator-=(Rational(rhs, 1)); }
  Rational& operator*=(const Rational& rhs);
  Rational& operator*=(const int& rhs) { return operator*=(Rational(rhs, 1)); }
  std::ostream& WriteTo(std::ostream& ostrm) const;
  std::istream& ReadFrom(std::istream& istrm);
private:
  static const char devide = '/';
  int devider = 1;
  int devisible = 0;
  int Gcd(int a, int b);
  void DevideByGcd(int& lhs, int& rhs);
  
  // int Lcm(int a, int b);
};

Rational operator+(const Rational& lhs, const Rational& rhs);

Rational operator-(const Rational& lhs, const Rational& rhs);

Rational operator*(const Rational& lhs, const Rational& rhs);

inline std::ostream& operator<<(std::ostream& ostrm, const Rational& rhs) { return rhs.WriteTo(ostrm); }

inline std::istream& operator>>(std::istream& istrm, Rational& rhs) { return rhs.ReadFrom(istrm); }
#include <numeric>

class Rational
{
public:
  Rational() {}
  explicit Rational(const int m, const int n);
  bool operator==(const Rational& rhs) const { return (devider == rhs.devider) && (devisible == rhs.devisible); }
  bool operator!=(const Rational& rhs) const { return !operator==(rhs); }
private:
  int devider = 1;
  int devisible = 0;
  int Gcd(int a, int b);
};




#include <iostream>
#include <cmath>

#define EPS 1e-4

double y(double x) {
    return std::exp(x);
}

double s(double x) {
    int step = 0;
    double power = 1;
    int fact = 1;
    double sum = 0;
    while (power / fact - EPS > 0) {
        sum += power / fact;
        power *= 2 * x;
        fact *= step + 1;
        step++;
    }
    return sum;
}

int main() {
    for (double i = 0; 1.04 - i > EPS; i += 0.1) {
        std::cout << i << " " << s(i) << " " << y(i) << "\n";
    }

    return 0;
}


















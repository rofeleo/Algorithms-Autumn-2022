#include <iostream>
#include <cmath>

#define EPS 1e-3

double y(double x) {
    return cos(x);
}

double s(double x) {
    int step = 0;
    int fact = 1;
    double sum = 0;
    while (double(pow(x, 2 * step)) / fact > EPS) {
        sum += (step % 2 == 0 ? 1 : -1) * double(pow(x, 2 * step)) / fact;
        fact *= (step + 1) * (step + 2);
        step++;
    }
    return sum;
}

int main() {
    for (double i = -1; 1.1 - i > EPS; i += 0.1) {
        std::cout << i << " " << s(i) << " " << y(i) << "\n";
    }

    return 0;
}

#include <iostream>
#include <cmath>

const double kEps = 1e-3;


double y(double x) {
    return x * sin(M_PI / 4) / (1 - 2 * x * cos(M_PI / 4));
}



double s(double x) {
    double x_power(x);
    int step(1);
    double sum(0);
    while (x_power * sin(step * (M_PI / 4)) - kEps > 0) {
        sum += x_power * sin(step * M_PI / 4);
        x_power *= x;
        step++;
    }
    return sum;
}



int main() {
    for (double i(0); 1.04 - i > kEps; i += 0.05) {
        std::cout << i << " " << s(i) << " " << y(i) << "\n";
    }

    return 0;
}

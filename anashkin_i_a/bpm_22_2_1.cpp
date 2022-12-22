#include <iostream>
#include <cmath>

int main() {
	std::cout.precision(5);
	std::cout << std::fixed;
	const double kEps = 0.0001;
	double sum = 0;
	int i = 0, sign = 1;
	double x = 0.1, d_x = 0.05;
	while (1.04 - x >= kEps) {
		sum += sign * (std::pow(x, 2 * i + 1) / (2 * i + 1));
		std::cout << x << "\t" << sum << "\n";
		x += d_x;
		i += 1;
		sign *= -1;
	}
	return 0;
}

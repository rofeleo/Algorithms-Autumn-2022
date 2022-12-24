#include <iostream>
#include <cmath>

int main() {

	std::cout.precision(5);
	std::cout << std::fixed;

	const double kEps = 0.0001;

	double d_x = 0.05;
	double total_sum = 0;
	
	std::cout << "x\t\tsum for x\ttotal sum\n";

	for (double x = 0.1; 1.001 - x > kEps; x += d_x) {

		double cur_sum = 0;
		int i = 0, sign = 1;
		double summand = 0;

		do {
			summand = pow(x, 2 * i + 1) / (2 * i + 1);
			cur_sum += sign * summand;
			i += 1;
			sign *= -1;
		} while (summand > kEps);

		total_sum += cur_sum;
		std::cout << x << "\t\t" << cur_sum << "\t\t" << total_sum << std::endl;
	}

	return 0;
}

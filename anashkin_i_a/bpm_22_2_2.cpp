#include <iostream>
#include <numeric>

double Parab(const double& x) {
	return 2 - x * x + 0.0001;
}

double Mod(const double& x) {
	return std::abs(x) - 0.0001;
}

int main() {
	const double kEps = std::numeric_limits<double>::epsilon();
	double x, y;
	int n_inside_area = 0;
	int n_all_point = 0;
	while (std::cin >> x >> y) {
		if (y - Parab(x) < kEps && y - Mod(x) > kEps) {
			n_inside_area += 1;
		}
		n_all_point += 1;
		std::cout << n_inside_area << std::endl;
	}
	std::cout << 1.0 * n_inside_area / n_all_point;
	return 0;
}

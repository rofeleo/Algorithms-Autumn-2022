#include <iostream>

void solve() {
    int n_floors;
    std::cin >> n_floors;
    for (int floor(0); floor < n_floors; floor += 1) {
        std::cout << 1 << " ";
        for (int mesh(0); mesh < floor - 1; mesh += 1) {
            std::cout << 0 << " ";
        }
        if (floor > 0) {
            std::cout << 1;
        }
        std::cout << "\n";
    }
}


int main() {
    int n_tests;
    std::cin >> n_tests;
    while (n_tests--) {
        solve();
    }

    return 0;
}

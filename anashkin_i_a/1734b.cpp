#include <iostream>

void solve() {
    int floors;
    std::cin >> floors;
    for (int floor = 0; floor < floors; floor++) {
        std::cout << 1 << " ";
        for (int mesh = 0; mesh < floor - 1; mesh++) {
            std::cout << 0 << " ";
        }
        if (floor > 0) {
            std::cout << 1;
        }
        std::cout << "\n";
    }
}


int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        solve();
    }

    return 0;
}

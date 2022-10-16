#include <iostream>

#define INF 1000000

void solve() {
    int days;
    std::cin >> days;
    bool is_water_tomorrow(false);
    int flower(1);
    bool is_alive(true);
    for (int day(1); day <= days; ++day) {
        bool is_water_now;
        std::cin >> is_water_now;
        if (is_water_now) {
            if (is_water_tomorrow) {
                flower += 5;
            } else {
                flower++;
            }
        } else if (!is_water_tomorrow && day > 1) {
            flower = -INF;
        }
        is_water_tomorrow = is_water_now;
    }
    std::cout << std::max(flower, -1);
}


int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        solve();
        std::cout << "\n";
    }
    return 0;
}

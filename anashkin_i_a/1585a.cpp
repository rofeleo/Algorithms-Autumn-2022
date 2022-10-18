#include <iostream>



void solve() {
    int n_days;
    std::cin >> n_days;
    bool is_watered_tomorrow(false);
    int flower(1);
    bool is_alive(true);
    const int kInf = 1000000;
    for (int day(1); day <= n_days; day += 1) {
        bool is_water_now;
        std::cin >> is_water_now;
        if (is_water_now) {
            if (is_watered_tomorrow) {
                flower += 5;
            } else {
                flower++;
            }
        } else if (!is_watered_tomorrow && day > 1) {
            flower = -kInf;
        }
        is_watered_tomorrow = is_water_now;
    }
    std::cout << std::max(flower, -1);
}


int main() {
    int n_tests;
    std::cin >> n_tests;
    while (n_tests--) {
        solve();
        std::cout << "\n";
    }
    return 0;
}

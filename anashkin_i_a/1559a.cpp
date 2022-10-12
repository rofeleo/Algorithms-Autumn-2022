#include <iostream>
#include <vector>

void solve() {
    int cnt_nums;
    std::cin >> cnt_nums;
    int all_conj;
    for (int i = 0; i < cnt_nums; ++i) {
        int num;
        std::cin >> num;
        if (i) {
            all_conj &= num;
        } else {
            all_conj = num;
        }
    }
    std::cout << all_conj;
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

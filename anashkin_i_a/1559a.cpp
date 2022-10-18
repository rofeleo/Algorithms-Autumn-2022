#include <iostream>
#include <vector>


void solve() {
    int n_nums;
    std::cin >> n_nums;
    int all_conj;
    for (int i(0); i < n_nums; i += 1) {
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
    int n_tests;
    std::cin >> n_tests;
    while (n_tests--) {
        solve();
        std::cout << "\n";
    }

    return 0;
}

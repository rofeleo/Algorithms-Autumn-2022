#include <iostream>

void solve() {
    int u_l, u_r, l_l, l_r;
    std::cin >> u_l >> u_r >> l_l >> l_r;
    if (u_l && u_r && l_l && l_r) { std::cout << 2; }
    else if (!(u_l || u_r || l_l || l_r)) { std::cout << 0; }
    else { std::cout << 1; }
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

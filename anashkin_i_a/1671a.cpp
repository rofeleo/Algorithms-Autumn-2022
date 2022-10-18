#include <iostream>



void solve() {
    std::string s;
    std::cin >> s;
    int streak(1);
    for (int i(1); i < s.size(); i += 1) {
        if (s[i] != s[i - 1]) {
            if (streak == 1) {
                std::cout << "NO";
                return;
            }
            streak = 0;
        }
        streak++;
    }
    if (s.size() > 1 && streak > 1) { std::cout << "YES"; }
    else { std::cout << "NO"; }
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

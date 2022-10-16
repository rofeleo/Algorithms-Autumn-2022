#include <iostream>
#include <vector>

void solve() {
    
    int locations;
    std::cin >> locations;
    
    std::vector<bool> is_earth(locations);
    
    for (int i(0); i < locations; ++i) {
        // std::cin >> is_earth[i]; Will not work. I don't know why.
        int cur_loc;
        std::cin >> cur_loc;
        is_earth[i] = cur_loc;
    }
    
    std::vector<bool>::iterator left(is_earth.begin()), right(is_earth.end() - 1);
    
    while (left != is_earth.end() && *left) {
        left++;
    }

    if (left == is_earth.end()) {
        std::cout << 0;
        return;
    }

    while (*right) {
        right--;
    }

    std::cout << right - left + 2;
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

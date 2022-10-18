#include <iostream>
#include <vector>
#include <algorithm>



void solve() {
    int n_nums;
    std::cin >> n_nums;
    std::vector<int> nums;
    bool thr_is_zero = 0;
    for (int i(0); i < n_nums; i += 1) {
        int num;
        std::cin >> num;
        if (!num) {
            thr_is_zero = 1;
        } else {
            nums.push_back(num);
        }
    }
    n_nums = nums.size();

    std::sort(nums.begin(), nums.end());

    int ans = 0;

    if (!thr_is_zero) {
        for (int i(1); i < n_nums; i += 1) {
            if (nums[i - 1] == nums[i]) {
                thr_is_zero = 1;
                nums[i] = -1;
                ans++;
            }
        }
    }

    if (!thr_is_zero) {
        ans += 2;
        nums[0] = -1;
    }
    for (int i(0); i < n_nums; i += 1) {
        if (nums[i] != -1) {
            ans += 1;
        }
    }
    std::cout << ans;
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

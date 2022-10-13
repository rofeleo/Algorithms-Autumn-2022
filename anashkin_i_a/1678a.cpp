#include <iostream>
#include <vector>
#include <algorithm>

void solve() {
    int cnt_nums;
    std::cin >> cnt_nums;
    std::vector<int> nums;
    bool thr_is_zero = 0;
    for (int i = 0; i < cnt_nums; ++i) {
        int num;
        std::cin >> num;
        if (!num) {
            thr_is_zero = 1;
        } else {
            nums.push_back(num);
        }
    }
    cnt_nums = nums.size();

    std::sort(nums.begin(), nums.end());

    int ans = 0;

    if (!thr_is_zero) {
        for (int i = 1; i < cnt_nums; ++i) {
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
    for (int i = 0; i < cnt_nums; ++i) {
        if (nums[i] != -1) {
            ans += 1;
        }
    }
    std::cout << ans;
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

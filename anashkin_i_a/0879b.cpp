#include <iostream>
#include <vector>


int main() {
  int n_people;
  long long win_streak;
  std::cin >> n_people >> win_streak;
  int cur_max_power(0);
  long long cur_win_streak(0);
  for (int i_power(0); i_power < n_people; i_power += 1) {
    int cur_power;
    std::cin >> cur_power;
    if (cur_power < cur_max_power) { cur_win_streak += 1; }
    else {
      cur_max_power = cur_power;
      cur_win_streak = 1;
      if (i_power == 0) cur_win_streak -= 1;
    }
    if (cur_win_streak == win_streak) {
      std::cout << cur_max_power;
      return 0;
    }
  }
  std::cout << cur_max_power;
  return 0;
}
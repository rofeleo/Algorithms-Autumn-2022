#include<iostream>
#include <vector>
#include <set>

int main() {
  int n_canteens;
  std::cin >> n_canteens;
  std::vector<int> canteen_numbers(n_canteens);
  for (int& i : canteen_numbers) {
    std::cin >> i;
  }
  std::set<int> visited_canteen;
  int last_uniq_vis = 0;
  for (int i = n_canteens - 1; i >= 0; i -= 1) {
    if (!visited_canteen.count(canteen_numbers[i])) {
      visited_canteen.insert(canteen_numbers[i]);
      last_uniq_vis = canteen_numbers[i];
    }
  }
  std::cout << last_uniq_vis;
  return 0;
}
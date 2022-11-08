#include <iostream>
#include <vector>
#include <algorithm>

int main() {
  int n_contests;
  std::cin >> n_contests;
  std::vector<int> tasks(n_contests);
  for (int i_contest(0); i_contest < n_contests; ++i_contest) {
    std::cin >> tasks[i_contest];
  }
  std::sort(tasks.begin(), tasks.end());
  int n_need_solve_tasks(1);
  int i_contest(0);
  while (i_contest < n_contests) {
    if (n_need_solve_tasks <= tasks[i_contest]) {
      n_need_solve_tasks += 1;
    }
    i_contest += 1;
  }
  std::cout << n_need_solve_tasks - 1;
  return 0;
}
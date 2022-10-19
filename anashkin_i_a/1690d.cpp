#include <iostream>
#include <string>


void solve() {

  int len_paper, len_black_streak;
  std::cin >> len_paper >> len_black_streak;

  std::string paper; 
  std::cin >> paper;
  
  int min_paint_total(len_black_streak);
  int need_paint_now(0);
  
  int i_paper(0);

  for (; i_paper < len_black_streak; i_paper += 1) {
    if (paper[i_paper] == 'W') need_paint_now++;
  }

  min_paint_total = std::min(min_paint_total, need_paint_now);

  for (; i_paper < len_paper; i_paper += 1) {
    if (paper[i_paper] == 'W' && paper[i_paper - len_black_streak] == 'B') { 
      need_paint_now++; 
    } else if (paper[i_paper] == 'B' && paper[i_paper - len_black_streak] == 'W') { 
      need_paint_now--; 
    }
    min_paint_total = std::min(min_paint_total, need_paint_now);
  }

  std::cout << min_paint_total;

}



int main() {
  int n_tests;
  std::cin >> n_tests;
  while (n_tests--) {
    solve();
    std::cout << "\n";
  }
}

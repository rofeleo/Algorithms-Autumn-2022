#include<iostream>
#include <vector>
#include <algorithm>


int main() {
  
  int n_holes, v_water_in, v_water_out;
  
  std::cin >> n_holes >> v_water_in >> v_water_out;
  
  std::vector<int> hole_sizes;
  
  int v_water_out_now = 0;
  
  int first_hole_size = -1;
  
  long long sum_open_holes = 0;

  for (int i_hole = 0; i_hole < n_holes; i_hole += 1) {
    int hole_size;
    std::cin >> hole_size;
    if (!i_hole) { first_hole_size = hole_size; }
    else {
      hole_sizes.push_back(hole_size);
    }
    sum_open_holes += hole_size;
  }

  std::sort(hole_sizes.begin(), hole_sizes.end());

  auto cur_closing_hole = hole_sizes.end() - 1;

  int ans = 0;

  while (long long(v_water_in * first_hole_size) < long long(v_water_out * sum_open_holes)) {
    sum_open_holes -= *cur_closing_hole;
    ans += 1;
    if (cur_closing_hole > hole_sizes.begin()) cur_closing_hole--;
  }

  std::cout << ans;

  return 0;
}
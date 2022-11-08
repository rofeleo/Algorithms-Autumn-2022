#include<iostream>
#include <vector>


int main() {
  int n_parts, m; 
  std::cin >> n_parts >> m;
  std::vector<bool> s(m);
  n_parts %= m;
  while (!s[n_parts] && n_parts % m) {
    s[n_parts] = 1;
    n_parts *= 2;
    n_parts %= m;
  }
  if (n_parts % m == 0) {
    std::cout << "Yes";
  }
  else {
    std::cout << "No";
  }
  return 0;
}
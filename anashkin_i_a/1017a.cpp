#include<iostream>
#include <vector>
#include <set>

int main() {
  int n_students;
  std::cin >> n_students;
  int thomas_res = -1;
  int stud_above = 0;
  for (int i_student = 0; i_student < n_students; i_student += 1) {
    int student_score = 0;
    for (int i_subj = 0; i_subj < 4; i_subj += 1) {
      int subj; 
      std::cin >> subj;
      student_score += subj;
    }
    if (!i_student) { thomas_res = student_score; }
    else {
      if (student_score > thomas_res) {
        stud_above += 1;
      }
    }
  }
  std::cout << stud_above + 1;
  return 0;
}
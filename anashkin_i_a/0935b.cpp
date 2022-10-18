#include <iostream>
#include <string>

int FuncSign(int num_x, int num_y) {
    if (num_x - num_y == 0) return 0;
    else if (num_x - num_y < 0) return -1;
    else return 1;
}

int main() {
    int steps;
    std::cin >> steps;
    std::string way;
    std::cin >> way;

    int last_nz_x = 0, last_nz_y = 0;

    if (way[0] == 'U') last_nz_y = 1;
    if (way[0] == 'R') last_nz_x = 1;

    int cur_x = last_nz_x, cur_y = last_nz_y;

    int money = 0;

    for (int curStep = 1; curStep < steps; curStep += 1) {
        if (way[curStep] == 'U') {
            cur_y++;
        } else {
            cur_x++;
        }
        if (FuncSign(cur_x, cur_y)) {
            if (FuncSign(cur_x, cur_y) != FuncSign(last_nz_x, last_nz_y)) {
                money++;
            }
            last_nz_x = cur_x;
            last_nz_y = cur_y;
        }
    }

    std::cout << money;

    return 0;
}

#include <iostream>
#include <string>

int funcSign(int num_x, int num_y) {
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

    int curX = last_nz_x, curY = last_nz_y;

    int money = 0;

    for (int curStep = 1; curStep < steps; ++curStep) {
        if (way[curStep] == 'U') {
            curY++;
        } else {
            curX++;
        }
        if (funcSign(curX, curY)) {
            if (funcSign(curX, curY) != funcSign(last_nz_x, last_nz_y)) {
                money++;
            }
            last_nz_x = curX;
            last_nz_y = curY;
        }
    }

    std::cout << money;

    return 0;
}

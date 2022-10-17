#include <iostream>
#include <vector>

#define SIDE 8

bool is_at_field(const int& i_col, const int& i_row) {
    return i_col < SIDE && i_row < SIDE;
}

void solve() {
    
    char field[SIDE][SIDE];
    
    for (int i_col(0); i_col < SIDE; ++i_col) {
        for (int i_row(0); i_row < SIDE; ++i_row) {
            std::cin >> field[i_col][i_row];
        }
    }

    int offset[4][2]{
        {1, 1},
        {-1, -1},
        {-1, 1},
        {1, -1}
    };

    for (int i_col(0); i_col < SIDE; ++i_col) {
        for (int i_row(0); i_row < SIDE; ++i_row) {
            int i_offset(0);
            for (; i_offset < 4; ++i_offset) {
                int i_col_next(offset[i_offset][0] + i_col), i_row_next(offset[i_offset][1] + i_row);
                if (!(is_at_field(i_col_next, i_row_next) && field[i_col_next][i_row_next] == '#')) {
                    break;
                }
            }
            if (i_offset == 4) {
                std::cout << i_col + 1 << " " << i_row + 1;
                return;
            }
        }
    }

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

#include <iostream>
#include <vector>

const int kSide = 8;

bool IsAtField(const int& i_col, const int& i_row) {
    return i_col < kSide && i_row < kSide;
}

void solve() {
    
    char field[kSide][kSide];
    
    for (int i_col(0); i_col < kSide; i_col += 1) {
        for (int i_row(0); i_row < kSide; i_row += 1) {
            std::cin >> field[i_col][i_row];
        }
    }

    int offset[4][2]{
        {1, 1},
        {-1, -1},
        {-1, 1},
        {1, -1}
    };

    for (int i_row(0); i_row < kSide; i_row += 1) {
        for (int i_col(0); i_col < kSide; i_row += 1) {
            int i_offset(0);
            for (; i_offset < 4; ++i_offset) {
                int i_row_next(offset[i_offset][0] + i_row), i_col_next(offset[i_offset][1] + i_col);
                if (!(IsAtField(i_row_next, i_col_next) && field[i_row_next][i_col_next] == '#')) {
                    break;
                }
            }
            if (i_offset == 4) {
                std::cout << i_row + 1 << " " << i_col + 1;
                return;
            }
        }
    }

}


int main() {
    int n_tests;
    std::cin >> n_tests;
    while (n_tests--) {
        solve();
        std::cout << "\n";
    }
    return 0;
}

#include <iostream>
#include <vector>

struct Coord {
   int x, y;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<Coord> stars;
    for (int i_row(0); i_row < n; i_row += 1) {
        for (int i_col(0); i_col < n; i_col += 1) {
            char c;
            std::cin >> c;
            if (c == '*') stars.push_back({i_row, i_col});
        }
    }
    std::vector<int> x_unique, y_unique;
    if (stars[0].x != stars[1].x && stars[0].y != stars[1].y) {
        x_unique.push_back(stars[0].x);
        x_unique.push_back(stars[1].x);
        y_unique.push_back(stars[0].y);
        y_unique.push_back(stars[1].y);

    } else if (stars[0].x != stars[1].x) {
        x_unique.push_back(stars[0].x);
        x_unique.push_back(stars[1].x);
        y_unique.push_back(stars[0].y);
        if (y_unique[0] + 1 < n) {
            y_unique.push_back(stars[0].y + 1);
        } else {
            y_unique.push_back(stars[0].y - 1);
        }
    } else {
        y_unique.push_back(stars[0].y);
        y_unique.push_back(stars[1].y);
        x_unique.push_back(stars[0].x);
        if (x_unique[0] + 1 < n) {
            x_unique.push_back(stars[0].x + 1);
        } else {
            x_unique.push_back(stars[0].x - 1);
        }
    }
    for (int i_row(0); i_row < n; i_row += 1) {
        for (int i_col(0); i_col < n; i_col += 1) {
            if ((i_row == x_unique[0] || i_row == x_unique[1]) && (i_col == y_unique[1] || i_col == y_unique[0])) {
                std::cout << '*';
            } else {
                std::cout << '.';
            }
        }
        std::cout << "\n";
    }
}

int main() {
    int n_tests;
    std::cin >> n_tests;
    while (n_tests--) {
        solve();
    }

    return 0;
}

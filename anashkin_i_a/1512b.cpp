#include <iostream>
#include <vector>

struct coord{
   int x, y;
};

void solve() {
    int n;
    std::cin >> n;
    std::vector<std::vector<char>> field(n, std::vector<char>(n));
    std::vector<coord> stars;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cin >> field[i][j];
            if (field[i][j] == '*') stars.push_back({i, j});
        }
    }
    std::vector<int> X, Y;
    if (stars[0].x != stars[1].x && stars[0].y != stars[1].y) {
        X.push_back(stars[0].x);
        X.push_back(stars[1].x);
        Y.push_back(stars[0].y);
        Y.push_back(stars[1].y);

    } else if (stars[0].x != stars[1].x) {
        X.push_back(stars[0].x);
        X.push_back(stars[1].x);
        Y.push_back(stars[0].y);
        if (Y[0] + 1 < n) {
            Y.push_back(stars[0].y + 1);
        } else {
            Y.push_back(stars[0].y - 1);
        }
    } else {
        // stars[0].y != stars[1].y
        Y.push_back(stars[0].y);
        Y.push_back(stars[1].y);
        X.push_back(stars[0].x);
        if (X[0] + 1 < n) {
            X.push_back(stars[0].x + 1);
        } else {
            X.push_back(stars[0].x - 1);
        }
    }
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 2; ++j) {
            field[X[i]][Y[j]] = '*';
        }
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            std::cout << field[i][j];
        }
        std::cout << "\n";
    }
}

int main() {
    int tests;
    std::cin >> tests;
    while (tests--) {
        solve();
    }

    return 0;
}

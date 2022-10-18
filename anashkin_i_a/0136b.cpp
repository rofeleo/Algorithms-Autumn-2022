#include <iostream>
#include <vector>


void ConvTernNs(std::vector<int>& res, int a) {
    while (a) {
        res.push_back(a % 3);
        a /= 3;
    }
}



int main() {

    int a, c;

    std::cin >> a >> c;
    std::vector<int> tern_a, tern_c;

    ConvTernNs(tern_a, a);
    ConvTernNs(tern_c, c);

    while (tern_a.size() < tern_c.size()) {
        tern_a.push_back(0);
    }
    while (tern_c.size() < tern_a.size()) {
        tern_c.push_back(0);
    }

    std::vector<int> tern_b;

    for (int i(0); i < tern_a.size(); i += 1) {
        tern_b.push_back((3 + (tern_c[i] - tern_a[i])) % 3);
    }

    int tern_b_pow = 1;

    int b = 0;

    for (int i : tern_b) {
        b += i * tern_b_pow;
        tern_b_pow *= 3;
    }

    std::cout << b;

    return 0;
}
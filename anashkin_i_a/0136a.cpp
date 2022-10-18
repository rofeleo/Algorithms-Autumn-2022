#include <iostream>
#include <vector>


int main() {
    int n_friends;
    std::cin >> n_friends;
    std::vector<int> gift_from(n_friends);
    for (int i(0); i < n_friends; i += 1) {
        int gift_to;
        std::cin >> gift_to;
        gift_from[--gift_to] = 1 + i;
    }
    for (const int& i : gift_from) {
        std::cout << i << " ";
    }
    return 0;
}

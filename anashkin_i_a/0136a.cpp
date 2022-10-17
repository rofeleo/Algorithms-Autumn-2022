#include <iostream>
#include <vector>


int main() {
    int friends;
    std::cin >> friends;
    std::vector<int> gift_from(friends);
    for (int i(0); i < friends; ++i) {
        int gift_to;
        std::cin >> gift_to;
        gift_from[--gift_to] = 1 + i;
    }
    for (const int& i : gift_from) {
        std::cout << i << " ";
    }
    return 0;
}

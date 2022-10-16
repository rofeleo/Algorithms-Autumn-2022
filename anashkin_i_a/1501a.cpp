#include <iostream>
#include <vector>



void solve() {
    
    int stations;
    std::cin >> stations;
    
    std::vector<int> arrive(1 + stations), leave(1 + stations);
    std::vector<int> stay(1 + stations);
    
    for (int station = 1; station <= stations; ++station) {
        std::cin >> arrive[station] >> leave[station];
        stay[station] = (leave[station] - arrive[station] + 1) >> 1;
    }
    
    int delay = 0;
    for (int station = 1; station <= stations; ++station) {
        std::cin >> delay;
        arrive[station] += delay;
    }

    for (int station = 1; station < stations; ++station) {
        if (arrive[station] + stay[station] > leave[station]) {
            arrive[station + 1] += arrive[station] + stay[station] - leave[station];
        }
    }

    std::cout << arrive.back();

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

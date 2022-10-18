#include <iostream>
#include <vector>



void solve() {
    
    int n_stations;
    std::cin >> n_stations;
    
    std::vector<int> arrive(1 + n_stations), leave(1 + n_stations);
    std::vector<int> stay(1 + n_stations);
    
    for (int station(1); station <= n_stations; station += 1) {
        std::cin >> arrive[station] >> leave[station];
        stay[station] = (leave[station] - arrive[station] + 1) >> 1;
    }
    
    int delay(0);
    for (int station(1); station <= n_stations; station += 1) {
        std::cin >> delay;
        arrive[station] += delay;
    }

    for (int station(1); station < n_stations; station += 1) {
        if (arrive[station] + stay[station] > leave[station]) {
            arrive[station + 1] += arrive[station] + stay[station] - leave[station];
        }
    }

    std::cout << arrive.back();

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

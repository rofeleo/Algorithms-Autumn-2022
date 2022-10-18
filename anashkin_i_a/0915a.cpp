#include <iostream>


int main() {
    int buckets, garden_len;
    std::cin >> buckets >> garden_len;
    int time = 1000000;
    for (int i = 0; i < buckets; i += 1) {
        int bucket_seg;
        std::cin >> bucket_seg;
        if (garden_len % bucket_seg == 0) {
            time = std::min(time, garden_len / bucket_seg);
        }
    }
    std::cout << time;
    return 0;
}

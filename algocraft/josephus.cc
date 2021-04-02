#include <iostream>
#include <memory>
#include <vector>

int Josephus(int n, int k) {
    std::vector<int> all(n);
    for (auto i = 0; i < n; i++) {
        all[i] = i;
    }

    auto startI = 0;
    for (; n > 1; n--) {
        auto t = (startI + k) % n;
        auto it = all.begin() + t;
        it = all.erase(it);
        if (it == all.end()) it = all.begin();

        startI = it - all.begin();
    }
    return all[0];
}

int main() {
    int n = 5, k = 2;
    std::cout << "n - " << n << " "
              << "k - " << k << "\n";
    auto r = Josephus(n, k);
    std::cout << "Result of JosephusGame: " << r << "\n";
}
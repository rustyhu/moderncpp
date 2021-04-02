#include <iostream>
#include <memory>
#include <vector>

int main() {
    std::vector<int> avec;
    avec.reserve(8);
    std::cout << "avec capacity: " << avec.capacity() << "\n";

    avec.push_back(-13);

    std::cout << "avec size: " << avec.size() << "\n";
    std::cout << "avec content: [";
    for (const auto& e : avec) {
        std::cout << e << " ";
    }
    std::cout << "]\n";
}
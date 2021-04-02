#include <iostream>
#include <string>

template <typename F, typename... Args>
void Caller(F f, int num, Args... args) {
    std::cout << "Get a number: " << num << "\n";
    f(num, args...);
}

void f1(int num) { std::cout << "f1 passed in and get: " << num << "\n"; }

void f2(int num, int p2, std::string p3) {
    std::cout << "f2 passed in and get: " << num << ", Get more: " << p3
              << "\n";
}

int main() {
    Caller(f1, 3);
    Caller(f2, 99, 22, "kkk");
    return 0;
}
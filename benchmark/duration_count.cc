#include "duration_count.h"

#include <chrono>
#include <functional>
#include <iostream>

void addBenchmark(std::function<void()> f) {
    auto start = std::chrono::high_resolution_clock::now();

    f();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    // std::chrono::nanoseconds elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

// template <typename F, typename... ARG>
// void addBenchmarkTmpl(F f, ARG &&...arg) {
template <typename F>
void addBenchmarkTmpl(F f) {
    auto start = std::chrono::high_resolution_clock::now();

    // f(std::forward<ARG>(arg)...);
    f();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    // std::chrono::nanoseconds elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

// MACRO form with source code input
#define ADDBENCHMARK(SRC)                                           \
    do {                                                            \
        auto start = std::chrono::high_resolution_clock::now();     \
        { SRC }                                                     \
        auto finish = std::chrono::high_resolution_clock::now();    \
        std::chrono::duration<double> elapsed = finish - start;     \
        std::cout << "Elapsed time: " << elapsed.count() << " s\n"; \
    } while (0)

void tmpF() {
    constexpr int N = 1000;
    int res[N][N];
    for (size_t i = 0; i < N; i++) {
        for (size_t j = 0; j < N; j++) {
            res[i][j] = 10;
        }
    }
    std::cout << "Read head " << res[0][0] << " and rear " << res[N - 1][N - 1]
              << "\n";
}

int main(int argc, char const *argv[]) {
    std::cout << "Macro:\n";
    ADDBENCHMARK(
        // portion of code to be timed...
        // constexpr int N = 1000; int res[N][N]; for (size_t i = 0; i < N; i++)
        // {
        //     for (size_t j = 0; j < N; j++) {
        //         res[i][j] = 10;
        //     }
        // } std::cout << "Read head "
        //             << res[0][0] << " and rear " << res[N - 1][N - 1] <<
        //             "\n";);
        tmpF(););

    std::cout << "std::function lambda:\n";
    addBenchmark([]() {
        constexpr int N = 1000;
        int res[N][N];
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                res[i][j] = 10;
            }
        }
        std::cout << "Read head " << res[0][0] << " and rear "
                  << res[N - 1][N - 1] << "\n";
    });

    std::cout << "std::function function pointer:\n";
    addBenchmark(tmpF);

    std::cout << "Template:\n";
    addBenchmarkTmpl(tmpF);
}

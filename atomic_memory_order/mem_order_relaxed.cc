#include <atomic>
#include <iostream>
#include <thread>
#include <vector>

void addBenchmark(std::function<void()> f) {
    auto start = std::chrono::high_resolution_clock::now();

    f();

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    // std::chrono::nanoseconds elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";
}

/*
typedef enum memory_order {
    memory_order_relaxed,
    memory_order_consume,
    memory_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst
} memory_order;
*/

// a cppref example

std::atomic<int> cnt = {0};

void f() {
    for (int n = 0; n < 1000; ++n) {
        cnt += 1;
        // cnt.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    for (size_t i = 0; i < 10; i++) {
        addBenchmark([]() {
            std::vector<std::thread> v;
            for (int n = 0; n < 10; ++n) {
                v.emplace_back(f);
            }
            for (auto& t : v) {
                t.join();
            }
            std::cout << "Final counter value is " << cnt << '\n';
        });
    }
}
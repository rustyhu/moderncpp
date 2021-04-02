#include <iostream>
#include <mutex>
#include <atomic>

// consider the mechinism of atomics and spinlock
class spinlock {
    std::atomic_flag lock_;

public:
    spinlock() {
        lock_.clear();
    }

    inline void lock() {
        while (lock_.test_and_set(std::memory_order_acquire)) {}
    }
    
    inline void unlock() {
        lock_.clear(std::memory_order_release);
    }
};

class Mutexlock {
    std::mutex lock_;

public:
    inline void lock() {
        lock_.lock();
    }

    inline void unlock() {
        lock_.unlock();
    }
};

int main() {
}
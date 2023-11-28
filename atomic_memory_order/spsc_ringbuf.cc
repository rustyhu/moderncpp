// https://www.boost.org/doc/libs/1_83_0/libs/atomic/doc/html/atomic/usage_examples.html#boost_atomic.usage_examples.example_ringbuffer

// A wait-free ring buffer provides a mechanism for relaying objects from one
// single "producer" thread to one single "consumer" thread without any locks.
// The operations on this data structure are "wait-free" which means that each
// operation finishes within a constant number of steps. This makes this data
// structure suitable for use in hard real-time systems or for communication
// with interrupt/signal handlers.

#include <atomic>

using std::size_t;

template <typename T, size_t Size>
class ringbuffer {
 public:
  ringbuffer() : head_(0), tail_(0) {}

  bool push(const T& value) {
    size_t head = head_.load(std::memory_order_relaxed);
    size_t next_head = next(head);
    // full situation
    if (next_head == tail_.load(std::memory_order_acquire)) {
      return false;
    }

    ring_[head] = value;
    head_.store(next_head, std::memory_order_release);
    return true;
  }

  bool pop(T& value) {
    size_t tail = tail_.load(std::memory_order_relaxed);
    // empty situation
    if (tail == head_.load(std::memory_order_acquire)) {
      return false;
    }

    value = ring_[tail];
    tail_.store(next(tail), std::memory_order_release);
    return true;
  }

 private:
  size_t next(size_t current) { return (current + 1) % Size; }

  T ring_[Size];
  std::atomic<size_t> head_, tail_;
};

int main() {}
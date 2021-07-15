#include <functional>
#include <iostream>

// How to imitate function template partial specification?
// use Template Tag Dispatching

struct NormalTag {};
struct IntSpecialTag {};

template <typename T>
struct SomeTrait {
  using Tag = NormalTag;
};
// partial specification
template <>
struct SomeTrait<int> {
  using Tag = IntSpecialTag;
};

template <typename A, typename B>
void internalF(A a, B b, NormalTag) {
  std::cout << "Normal version." << std::endl;
}

template <typename A, typename B>
void internalF(A a, B b, IntSpecialTag) {
  std::cout << "Partial version." << std::endl;
}

// Interface for outside user
template <typename A, typename B>
void publicF(A a, B b) {
  internalF(a, b, typename SomeTrait<B>::Tag{});
}

int main(void) {
  int a = 10;
  double b = 12;

  publicF(a, b);
  publicF(a, a);
}

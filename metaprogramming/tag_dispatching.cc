#include <functional>
#include <iostream>

// How to imitate function template partial specification?

struct NormalTag {};
struct IntSpecialTag {};

template <typename T>
struct SomeTrait {
  using Tag = NormalTag;
};
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

/// Comparing the following another way, consider when you can not assign a
///`Tag` to `B` type, this trait is useful. I guess it may be situation when you
/// need POD sometimes. https://stackoverflow.com/a/7189821/4366445

// Interface for outside user
template <typename A, typename B>
void publicF(A a, B b) {
  internalF(a, b, typename SomeTrait<B>::Tag{});
}

///// another way
struct ReqTypeA {
  using Tag = NormalTag;
  int a;
  /// other members...
};

struct ReqTypeB {
  using Tag = IntSpecialTag;
  int a;
  /// other members...
};

template <typename A, typename B>
void publicF2(A a, B b) {
  if (std::is_same<typename B::Tag, IntSpecialTag>::value) {
    std::cout << "Partial version." << std::endl;
  } else {
    std::cout << "Normal version." << std::endl;
  }
}

int main(void) {
  int a = 10;
  double b = 12;

  publicF(a, b);
  publicF(a, a);

  ReqTypeA rA{};
  ReqTypeB rB{};
  publicF2(a, rA);
  publicF2(a, rB);
}

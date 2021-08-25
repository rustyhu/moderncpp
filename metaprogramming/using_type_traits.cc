#include <iostream>

// https://en.cppreference.com/w/cpp/types
// <type_traits>
// Type traits defines a compile-time template-based interface to query or
// modify the properties of types. A template defined in the <type_traits>
// header may be instantiated with an incomplete type unless otherwise
// specified, notwithstanding the general prohibition against instantiating
// standard library templates with incomplete types.

// the partial specialization of A is enabled via a template parameter
template <class T, class Enable = void>
class A {
 public:
  void show() { std::cout << "primary\n"; };
};  // primary template

template <class T>
class A<T, typename std::enable_if<std::is_floating_point<T>::value>::type> {
 public:
  void show() {
    // auto v = std::is_floating_point<T>::value;
    std::cout << "Get value: " << std::is_floating_point<T>::value
              << "   special float\n";
  };
};  // specialization for floating point types

int main() {
  A<char> ac;
  ac.show();

  A<int, int> af{};  // OK: matches the primary template
  af.show();

  A<double> aa{};  // OK: matches the partial specialization
  aa.show();
}

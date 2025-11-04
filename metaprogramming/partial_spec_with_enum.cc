#include <iostream>

// Dispatch Enum
enum class DpEnum { K1 = 1, K2 = 2, Default = 3 };

template <DpEnum>
struct Behavior {
  int run(int x) { return x + 1; }
};

template <>
struct Behavior<DpEnum::K1> {
  int run(int x) { return x * x; }
};

template <>
struct Behavior<DpEnum::K2> {
  int run(int x) { return (x + 2) / 2; }
};

int main() {
  Behavior<DpEnum::K1> behavior1;
  Behavior<DpEnum::K2> behavior2;
  Behavior<DpEnum::Default> behaviorDef;

  int x = 4;
  std::cout << "S1 behavior: " << behavior1.run(x) << std::endl;  // Output: 16
  std::cout << "S2 behavior: " << behavior2.run(x) << std::endl;  // Output: 3
  std::cout << "Default behavior: " << behaviorDef.run(x)
            << std::endl;  // Output: 5

  return 0;
}

#include <iostream>
#include <type_traits>

// https://stackoverflow.com/questions/9530928/checking-a-member-exists-possibly-in-a-base-class-c11-version/9531274#9531274

// Culled by SFINAE if reserve does not exist or is not accessible
template <typename T>
constexpr auto has_reserve_method() -> decltype(T::name, bool()) {
  return true;
}

// Used as fallback when SFINAE culls the template method
// constexpr bool has_reserve_method(...) { return false; }

struct Res1 {
  char name[16];
};

struct Res2 {
  std::string name;
};

struct Res3 {};

template <typename T, typename = void>
class DispT {
 public:
  DispT() { Hello(); }
  void Hello() { std::cout << "Hello!\n"; }
};

template <typename T>
class DispT<T, typename std::enable_if<has_reserve_method<T>()>::type> {
 public:
  DispT() { Bar(); }
  void Bar() { std::cout << "Bar!\n"; }
};

int main() {
  DispT<Res1> a;
  DispT<Res2> b;
  DispT<Res3> c;
}
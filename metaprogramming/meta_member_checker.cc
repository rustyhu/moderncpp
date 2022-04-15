#include <iostream>
#include <type_traits>

// involve
// https://stackoverflow.com/questions/9530928/checking-a-member-exists-possibly-in-a-base-class-c11-version/9531274#9531274

template <typename T, typename = void>
struct has_name : std::false_type {};
template <typename T>
struct has_name<T, decltype((void)T::name)> : std::true_type {};
// "(void)" in decltype() is used to:
// 1. Cast from "any type" (T::name) to "void" always works;
// 2. Make it compatible with default type parameter --
//      class template interface is defined by the original tmplate definition
//      totally, which should not be violated by partial template specialization

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
class DispT<T, typename std::enable_if<has_name<T>::value>::type> {
 public:
  DispT() { Bar(); }
  void Bar() { std::cout << "Bar!\n"; }
};

int main() {
  DispT<Res1> a;
  DispT<Res2> b;
  DispT<Res3> c;
}
#include <iostream>

struct TagTypical {};

struct Res1 {
  using tag = int;
};

struct Res2 {
  using tag = int;
};

struct Res3 {
  using tag = TagTypical;
};

struct TagWild {};
struct Res4 {
  using tag = TagWild;
};

struct Res5 {};

struct TagNotImplemented {};
struct Res6 {
  using tag = TagNotImplemented;
};

// incomplete class with no definition
template <typename T, typename Tag = typename T::tag>
class DispT;

template <typename T>
class DispT<T, int> {
 public:
  DispT() { Hello(); }
  void Hello() { std::cout << "int!\n"; }
};

template <typename T>
class DispT<T, TagTypical> {
 public:
  DispT() { Bar(); }
  void Bar() { std::cout << "Typical!\n"; }
};

// Need to make DispT private
template <typename T>
class EncapsulatedDisp : public DispT<T, typename T::tag> {};

int main() {
  DispT<Res1> a;
  EncapsulatedDisp<Res2> b;
  DispT<Res3> c;

  // Match failure
  // DispT<Res4> d; // TagWild
  // DispT<Res5> e; // No tag
  // DispT<Res6> f; // TagNotImplemented

  // explicitly indicated tag, forbidden by EncapsulatedDisp
  DispT<Res5, TagTypical> g;
}
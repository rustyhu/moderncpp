#include <iostream>
#include <string>
#include <vector>

using std::cout;

class SC {
 public:  // for easy validation
  int a_;
  std::string b_;
  bool c_;
  std::vector<int> v_;

 public:
  SC() : a_(1), b_(""), c_(true) {}
  // custom constructor.
  SC(int a, std::string b, bool c) : a_(a), b_(b), c_(c) {}
  // ~SC(){};
  // SC(const SC& o) { cout << "In copy constructor!\n"; }
  // SC(SC&&) = default;

  //  Dangerous: it is possible to use reference to move value!
  void update(std::vector<int>& vnew) { v_ = std::move(vnew); }
};

// Guide: (Refering to Rust move semantics, C++ move semantics may be quite
// error-prone to use!)
// 1. You should not use moved value any more. Forbid yourself as compiler does
// not check!
// 2. Keep passing by value when you want to move it between functions. Compiler
// allows you to pass reference to move!
// 3. When define move constructor or move assign operator for a type T, pay
// attention to its destructor behavior, as moved value still will be
// destructed!

template <typename CTN>
void show(const CTN& ctner, const std::string& note = "") {
  if (!note.empty()) {
    cout << note << ": ";
  }

  for (const auto& ele : ctner) {
    cout << ele << ", ";
  }
  cout << "\n";
}

int main() {
  std::vector<int> dt{10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
  show(dt, "At start, dt");

  auto ssc = SC(1, "kkkk", true);
  ssc.update(dt);
  show(dt, "after move, dt");
  show(ssc.v_, "after move, ssc v_");

  auto cssc = std::move(ssc);
  show(cssc.v_, "move create, cssc");
  show(ssc.v_, "move create, ssc");
}
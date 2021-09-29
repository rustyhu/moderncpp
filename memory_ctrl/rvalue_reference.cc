#include <functional>
#include <iostream>
#include <string>

// NOTICE: rvalue reference variables are lvalues
// https://en.cppreference.com/w/cpp/language/reference
// https://stackoverflow.com/questions/32620750/why-are-rvalues-references-variables-not-rvalue

// The concept `rvalue reference` is independent from move semantic, whereas is
// relative to move semantic. Rust has default move semantic, but no concept of
// rvalue reference.

int procF1(int a, int b) { return a + b; }

void procF2(int&& k) {
  std::cout << "F2 touch: " << k << " addr " << &k << "\n";
}

void procF3(int&& rv) {
  std::cout << "First touch: " << rv << " addr " << &rv << "\n";
  rv = -10;
  // error: cannot bind rvalue reference of type ‘int&&’ to lvalue of type ‘int’
  // procF2(rv);
  procF2(std::forward<int>(rv));
}

int main() { procF3(procF1(1, 2)); }
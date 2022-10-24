#include <iostream>

class ca {
  int v1;
  int v2;
  char sv[16];

 public:
  // If need to construct it at some custom memory,
  // constructors can be called only through placement new expression?
  ca() : v1(32) { std::cout << "Built.\n"; }
  ca(const ca& rf) : v1(rf.v1) { std::cout << "copy cons.\n"; }

  ~ca() { std::cout << "Destructed.\n"; }

  void operator=(const ca& rf) {
    v1 = rf.v1;
    std::cout << "copy assign.\n";
  }

  void printV1() { std::cout << "v1: " << v1 << "\n"; }
};

int main() {
  char pBuf[2048];
  *(int*)pBuf = 0;

  // ref https://en.cppreference.com/w/cpp/language/new#Placement_new
  // (standard single-object) placement new expression
  // call (non-allocating placement allocation function) new operator:
  // construct directly at the buf
  ca* pCA = new (pBuf) ca;

  // ca* pCA = reinterpret_cast<ca*>(pBuf);
  // *pCA = ca();  // copy assign

  pCA->printV1();
  pCA->~ca();
}
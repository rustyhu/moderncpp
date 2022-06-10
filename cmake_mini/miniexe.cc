#include <iostream>
#include <vector>

#include "src/simple_if.h"

int main() {
  constexpr int v_size = 32;
  std::vector<int> a(v_size);
  std::cout << "Real size " << a.size() << std::endl
            << "Real capacity " << a.capacity() << std::endl;

  simple_func("kk");
}

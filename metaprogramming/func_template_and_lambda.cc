#include <functional>
#include <iostream>
#include <map>
#include <string>
#include <vector>

class myInfo {
  int n_;

 public:
  myInfo() : n_(0) {}
  myInfo(int n) : n_(n) {}

  friend std::ostream& operator<<(std::ostream& o, myInfo& i) {
    o << i.n_;
    return o;
  }
};

myInfo adata[] = {5, 3, 2, 1};

template <typename DATA>
void Caller(std::function<DATA*()> Get) {
  for (auto& i : adata) {
    DATA* p = Get();
    *p = i;
  }
}

int main(void) {
  std::vector<myInfo> pool(5);
  std::cout << "Start:\n";
  for (auto& info : pool) {
    std::cout << info << "\n";
  }

  int idx = 0;
  Caller<myInfo>([&idx, &pool]() {
    int i = idx;
    idx++;
    return &pool[i];
  });

  std::cout << "After:\n";
  for (auto& info : pool) {
    std::cout << info << "\n";
  }
}

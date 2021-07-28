#include <iostream>
#include <vector>

int main(void) {
  auto fshow = [](const std::string prefix, const std::vector<int>& m) {
    std::cout << prefix << ": Size - " << m.size() << " Cap - " << m.capacity()
              << " sizeof - " << sizeof(m) << ";\n";
  };

  std::vector<int> msg;
  fshow("Start", msg);

  msg.reserve(10);
  fshow("After reserved", msg);

  for (size_t i = 0; i < 4; i++) {
    msg.emplace_back(i);
  }
  fshow("After push", msg);

  for (size_t i = 4; i < 17; i++) {
    msg.emplace_back(i);
  }
  fshow("After exhausted", msg);
}

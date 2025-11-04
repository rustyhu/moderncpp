#include <iostream>
#include <map>

template <typename T>
using Nmap = std::map<T, std::string>;

void showUsingTemplate() {
  Nmap<int> a = {
      {1, "name"},
      {2, "kkk"},
  };

  for (auto&& ele : a) {
    std::cout << ele.first << " : " << ele.second << std::endl;
  }
}

#include <iostream>

// special member functions of class
// https://stackoverflow.com/questions/4172722/what-is-the-rule-of-three/4172724#4172724

class SC {
 private:
  int id_ = 0;

 public:
  SC() = default;
  SC(const int id) : id_(id) { std::cout << "SC(const int id) called.\n"; }
  ~SC() { std::cout << "~SC() called.\n"; }

  SC(const SC& sc) : id_(sc.id_) {
    std::cout << "SC(const SC& sc) copy constructor called.\n";
  }
  // SC(const SC& sc) = delete;
  // SC(SC&& sc) : id_(sc.id_) { std::cout << "MOVE construct\n"; };

  SC& operator=(const SC&) = delete;
  SC& operator=(SC&& rf) = default;
};

int main() {
  SC a = 3;
  SC b = std::move(a);
  std::cout << "Move assign:\n";
  a = std::move(b);

  SC c(std::move(a));
}

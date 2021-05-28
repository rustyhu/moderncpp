#include <iostream>
#include <string>

#define DE(F, ...)                                                     \
  do {                                                                 \
    std::cout << "Function name: " #F " returns [" << (F(__VA_ARGS__)) \
              << "]\n";                                                \
  } while (0)

int f1(int a, int b, int c) { return a + b + c; }

std::string f2(std::string a, std::string b) { return a + b; }

#define CATIN(NAME) My##NAME##Def

#define QueryHold(TYPE)      \
  struct Query##TYPE##Info { \
    int VirtualID;           \
    int BusinessNo;          \
  }

QueryHold(Bank);
QueryHold(School);

int main() {
  int CATIN(First) = 0;
  int CATIN(One) = 0;
  MyFirstDef = 1;

  QuerySchoolInfo si;

  DE(f1, 4, 5, 6);
  DE(f2, "Hello", "world");
}
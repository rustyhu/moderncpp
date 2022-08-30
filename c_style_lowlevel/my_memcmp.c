#include <stdio.h>

int my_memcmp(const void* lhs, const void* rhs, size_t count) {
  const unsigned char* uclhs = (const unsigned char*)(lhs);
  const unsigned char* ucrhs = (const unsigned char*)rhs;

  size_t i = 0;
  // Loop1
  // while (i < count && uclhs[i] == ucrhs[i]) {
  //   ++i;
  // }

  // Loop2
  for (; i < count; i++) {
    if (uclhs[i] != ucrhs[i]) break;
  }

  if (i == count) return 0;
  return (uclhs[i] < ucrhs[i]) ? -1 : 1;
}

// testcase
int main() { printf("cmp: %d\n", my_memcmp("kkko", "kkkk", 4)); }
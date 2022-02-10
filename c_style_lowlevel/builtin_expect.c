#include <stdio.h>

// __builtin_expect is a GCC extension
// https://gcc.gnu.org/onlinedocs/gcc/Other-Builtins.html

// ref:
// https://stackoverflow.com/questions/7346929/what-is-the-advantage-of-gccs-builtin-expect-in-if-else-statements
// https://stackoverflow.com/questions/109710/how-do-the-likely-unlikely-macros-in-the-linux-kernel-work-and-what-is-their-ben

#define likely(x) __builtin_expect(!!(x), 1)

int main() {
  const int Times = 1000 * 10;
  // int testnum = 0;

  for (int i = 0; i < Times; i++) {
    // https://stackoverflow.com/questions/11227809/why-is-processing-a-sorted-array-faster-than-processing-an-unsorted-array/11227902#11227902
    // benefit from branch prediction success when you need extreme performance
    // optimization.
    if (likely(i > 1)) {
      // TODO: do other operation instead of print IO
      printf("Get a positive a!\n");
    }
  }

  return 0;
}
#include <cstdio>
#include <cstring>

void checkbyte(char (&buf)[16]) {
  // for (int i = 0; i< 16; i++) {
  for (int i : buf) {
    std::printf("%d, ", i);
    std::printf("\n");
  }
}

int main() {
  char buf[16] = "123456789A";
  checkbyte(buf);
  std::printf("Init: %s\n", buf);

  char srcstr[5] = "five";
  snprintf(buf, sizeof(buf), "%s", srcstr);
  // strncpy(buf, srcstr, sizeof(buf));
  // memcpy(buf, "five", sizeof(srcstr));
  checkbyte(buf);
  std::printf("After cpy: %s\n", buf);

  // std::printf("\n%d", sizeof("five"));
}
#include <stdio.h>

const char* GetLibVersion() {
  return "My lib V1.0.0 [" __DATE__ " - " __TIME__ "]";
}

int main(void) { printf("%s\n", GetLibVersion()); }
#include <cstdio>
#include <string>

#define likely(x) __builtin_expect(!!(x), 1)

int main() {
    printf("Input an int:\n");

    int a;
    scanf("%d", &a);
    if (likely(a > 1)) {
        printf("Get a positive a!\n");
    }

    return 0;
}
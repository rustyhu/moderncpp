#include <iostream>
#include <cstdio>

// default alignment is 8bytes
struct A {
    double d;
    short b;
    int a;
    short c;
    char e[5];
};

struct AA {
    double d;
    int a;
    char b;
    short c;
};

#pragma pack(4)
struct B
{
    int a;
    int c;
    char d;
    short b;
};

int main() {
    std::cout << "sizeof A: " << sizeof(A) << '\n';
    std::cout << "sizeof AA: " << sizeof(AA) << '\n';

    B b;
    std::cout << "sizeof: " << sizeof(b) << " alignof: " << alignof(b) << '\n';
    std::cout << &(b.a) << '\n';
    std::cout << &(b.c) << '\n';
    std::cout << (void*)&(b.d) << '\n';
    std::cout << &(b.b) << '\n';
}
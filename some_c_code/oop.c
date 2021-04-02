#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// OOP practise in C language
// Only "object programming" pattern implemented here.

// typedef struct VTable VTable;
// typedef struct VTable {
//     void (*print)(Thing* self);
// } VTable;

typedef struct Thing {
    // int data_;
    int id_;
    char name_[32];

    void (*print)(struct Thing* pth);
} Thing;

void print_hello(Thing* self) {
    // a member function
    printf("Hello, ID %d - %s\n", self->id_, self->name_);
}

Thing initThing(const int id, const char* name) {
    Thing th = {
        .id_ = id,
        .print = print_hello,
    };
    strncpy(th.name_, name, sizeof(th.name_));
    return th;
}

int main() {
    Thing th = initThing(3, "Thing3name");
    th.print(&th);
}
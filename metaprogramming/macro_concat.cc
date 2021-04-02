#include <iostream>
#include <string>

#define DE(F, ...)                                 \
    do {                                           \
        std::cout << "Function name: " #F << '\n'; \
        std::cout << (F(__VA_ARGS__)) << '\n';     \
    } while (0)

int f1(int a, int b, int c) { return a + b + c; }

std::string f2(std::string a, std::string b) { return a + b; }

#define CATIN(NAME) My##NAME##Def

#define QueryHold(GROUP)                     \
    struct SQuery##GROUP##StocktypeHoldReq { \
        int VirtualAssetID;                  \
        int AssetID;                         \
    }

QueryHold(Asset);

int main() {
    int CATIN(First) = 0;
    int CATIN(One) = 0;
    MyFirstDef = 1;

    SQueryAssetStocktypeHoldReq sqa;

    DE(f1, 4, 5, 6);
    DE(f2, "Hello", "world");
}
#include <iostream>
#include <vector>

int frontFun(bool errhappen) {
    if (errhappen) {
        // problem here!
        goto end;
    }

    int a{32};
    char tmpstr[64] = {0};
    std::vector<int32_t> col;

end:
    std::cout << "reach end!\n";
}

int frontFunSec(bool errhappen) {
    do {
        if (errhappen) {
            break;
        }

        int a{32};
        char tmpstr[64] = {0};
        std::vector<int32_t> col;

        // do something to these variables, like:
        std::cout << a << tmpstr << "\n";
    } while (0);

    std::cout << "reach end!\n";
}

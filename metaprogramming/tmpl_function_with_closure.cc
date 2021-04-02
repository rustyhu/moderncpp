#include <functional>
#include <iostream>

struct MetaData {
    int a = -1;
    int b = -1;
    std::string c;

    void show() {
        std::cout << a << "\n";
        std::cout << b << "\n";
        std::cout << c << "\n";
    }
};

struct AnotherData {
    std::string no;
    std::string name;
    void show() {
        std::cout << no << "\n";
        std::cout << name << "\n";
    }
};

// template<typename T>
// void tmplFuncWithClosure(int32_t intInfo, std::function<void(T&)> f)
template <typename M, typename T>
void tmplFuncWithClosure(int intInfo, T f) {
    M m;
    // m.show();
    f(m);

    std::cout << "Get intInfo: " << intInfo << "\n";
    // m.show();
}

int main() {
    constexpr int aa = 3;
    tmplFuncWithClosure<MetaData>(3, [](MetaData& refm) {
        refm.a = 66;
        refm.b = 700;
        refm.c = "modified";
    });

    tmplFuncWithClosure<AnotherData>(4, [](AnotherData& refm) {
        refm.no = "333";
        refm.name = "Myname is 666";
    });

    typedef int32_t (*LPFN_ENTRY)(void* lpContext);
    // using FUNCT = void(*)(int, std::string&);

    LPFN_ENTRY a = [](void* lc) -> int32_t {};
}
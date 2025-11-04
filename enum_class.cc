#include <cstdint>
#include <iostream>

enum class OptionalFieldType : std::uint8_t {
    Int8 = 0,
    Int16,
    Int32,
    Int64,
    Double,
    Binary = 87
};

int main() {
    // error: ‘Int32’ was not declared in this scope
    // auto a = Int32;
    OptionalFieldType k = OptionalFieldType::Int32;
    std::cout << (int)k << "\n";
    std::cout << (int)OptionalFieldType::Binary << "\n";
}

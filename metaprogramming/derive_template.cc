/*
Object oriented,
define a template in Base as INTERFACE,
then implement this template in Derived class
*/

#include <map>

class BaseGeneric {
   private:
    /* void */
   public:
    BaseGeneric() = default;
    ~BaseGeneric() = default;

    template <typename T, typename... ARGS>
    T getValue(ARGS... args);
};

class DeriveImpl : BaseGeneric {
   private:
    std::pair<int, int> value_;

   public:
    DeriveImpl() {}
    ~DeriveImpl() {}

    const std::pair<int, int>& getValue(int a) { return value_; }
};

#include <iostream>
#include <string>
#include <type_traits>

// involve
// https://stackoverflow.com/questions/9530928/checking-a-member-exists-possibly-in-a-base-class-c11-version/9531274#9531274

#define HAS_MEMBER_TMPL(MEMBER)             \
  template <typename T, typename = void>    \
  struct has_##MEMBER : std::false_type {}; \
  template <typename T>                     \
  struct has_##MEMBER<T, decltype((void)T::MEMBER)> : std::true_type {};
// "(void)" in decltype() is used to:
// 1. Cast from "any type" (T::name) to "void" always works;
// 2. Make it compatible with default type parameter --
//    class template interface is defined by the original tmplate definition
//    completely, which should not be violated by partial template
//    specialization.

HAS_MEMBER_TMPL(name)

template <typename T, typename = void>
class DispT {
 private:
  std::string s_ = "None!\n";

 public:
  DispT() { std::cout << s_; }
  std::string Hello() { return s_; }
};

template <typename T>
class DispT<T, typename std::enable_if<has_name<T>::value>::type> {
 private:
  std::string ss_ = "Exist!\n";

 public:
  DispT() { std::cout << ss_; }
  std::string Bar() { return ss_; }
};

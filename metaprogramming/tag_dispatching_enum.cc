/// Use enum and std::integral_constant to do tag-dispatching.
/// It looks cleaner and readable.
/// https://stackoverflow.com/questions/20368187/when-would-i-use-stdintegral-constant-over-constexpr

#include <iostream>
#include <type_traits>

enum TAGS { Usual, Special, Dangerous, Extra };
/// For short
// template <TAGS eTags>
// using TAGSType = std::integral_constant<TAGS, eTags>;

template <typename T>
void gotoN_impl(std::integral_constant<TAGS, TAGS::Usual>, T kkk) {
  std::cout << "GoTo 0 get " << kkk << '\n';
}

template <typename T>
void gotoN_impl(std::integral_constant<TAGS, Special>, T kkk) {
  std::cout << "GoTo 1 get " << kkk << '\n';
}

template <typename T>
void gotoN_impl(std::integral_constant<TAGS, Dangerous>, T kkk) {
  std::cout << "GoTo 2 get " << kkk << '\n';
}

template <typename T>
void gotoN_impl(std::integral_constant<TAGS, Extra>, T kkk) {
  std::cout << "GoTo 3 get " << kkk << '\n';
}

template <TAGS eTags, typename T>
void gotoN(T kkk) {
  gotoN_impl(std::integral_constant<TAGS, eTags>(), kkk);
}

int main() {
  gotoN<Usual>(1);
  gotoN<Special>(1);
  gotoN<Dangerous>(3);
  gotoN<Extra>(309);

  const TAGS tmpk = Extra;
  gotoN<tmpk>("My any type value!");

  constexpr auto x = 99;
  gotoN<(x >= 0 && x < 4) ? TAGS(x) : Extra>(-20);  // with a ternary operator
}
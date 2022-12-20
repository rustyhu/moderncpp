// https://stackoverflow.com/questions/2565097/higher-kinded-types-with-c
// Monad

template <template <typename> typename m>
struct Monad {
  template <typename a>
  static m<a> mreturn(const a&);

  template <typename a, typename b>
  static m<b> mbind(const m<a>&, m<b> (*)(const a&));
};

template <typename a>
struct Maybe {
  bool isNothing;
  a value;
};

template <>
struct Monad<Maybe> {
  template <typename a>
  static Maybe<a> mreturn(const a& v) {
    Maybe<a> x;
    x.isNothing = false;
    x.value = v;
    return x;
  }

  template <typename a, typename b>
  static Maybe<b> mbind(const Maybe<a>& action,
                        Maybe<b> (*function)(const a&)) {
    if (action.isNothing)
      return Maybe<b>{true, b{}};
    else
      return function(action.value);
  }
};

Maybe<char> tns(const int& n) {
  char a = (n % 10) + 'a';
  return Maybe<char>{false, a};
}

int main() {
  Monad<Maybe> mm;
  auto mma = mm.mreturn(30);

  auto mme = Maybe<int>{false, 10};
  auto kkk = mm.mbind(mme, tns);
}

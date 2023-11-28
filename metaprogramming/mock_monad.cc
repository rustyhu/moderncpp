// https://stackoverflow.com/questions/2565097/higher-kinded-types-with-c
// Monad

template <template <typename> typename M>
struct Monad {
  template <typename A>
  static M<A> mreturn(const A&);

  template <typename A, typename B>
  static M<B> mbind(const M<A>&, M<B> (*)(const A&));
};

template <typename A>
struct Maybe {
  bool isNothing;
  A value;
};

template <>
struct Monad<Maybe> {
  template <typename A>
  static Maybe<A> mreturn(const A& v) {
    Maybe<A> x;
    x.isNothing = false;
    x.value = v;
    return x;
  }

  template <typename A, typename B>
  static Maybe<B> mbind(const Maybe<A>& action, Maybe<B> (*func)(const A&)) {
    if (action.isNothing)
      return Maybe<B>{true, B{}};
    else
      return func(action.value);
  }
};

Maybe<char> tns(const int& n) {
  char v = (n % 10) + 'a';
  return Maybe<char>{false, v};
}

int main() {
  Monad<Maybe> mm;
  auto mma = mm.mreturn(30);

  auto mme = Maybe<int>{false, 10};
  auto kkk = mm.mbind(mme, tns);
}

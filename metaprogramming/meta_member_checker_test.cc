#define CATCH_CONFIG_MAIN
#include "meta_member_checker.h"

#include <string>

#include "../include/catch.hpp"

struct Res1 {
  char name[16];
};

struct Res2 {
  std::string name;
};

struct Res3 {};

TEST_CASE("Factorials are computed", "[factorial]") {
  DispT<Res1> a;
  REQUIRE(std::string(a.Bar()) == "Exist!\n");
  DispT<Res2> b;
  REQUIRE(std::string(b.Bar()) == "Exist!\n");
  DispT<Res3> c;
  REQUIRE(std::string(c.Hello()) == "None!\n");
}
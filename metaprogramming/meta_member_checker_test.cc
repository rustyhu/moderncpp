#define CATCH_CONFIG_MAIN
#include "meta_member_checker.h"

#include <string>

#include "../include/catch.hpp"

TEST_CASE("Factorials are computed", "[factorial]") {
  DispT<Res1> a;
  REQUIRE(std::string(a.Bar()) == "Bar!\n");
  DispT<Res2> b;
  REQUIRE(std::string(b.Bar()) == "Bar!\n");
  DispT<Res3> c;
  REQUIRE(std::string(c.Hello()) == "Hello!\n");
}